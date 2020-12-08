#include "csapp.h"
#include <sys/epoll.h>
#include "ae.h"

#define MAX_EVENTS 256

int main(int argc, char* argvs[]) {
    int listen_fd;
    int client_fd;
    char client_host[256];
    char client_port[256];
    int clientaddr_len;
    rio_t rio;
    int i;
    int efd;
    int event_count;
    struct epoll_event event; 
    struct epoll_event *events;// 存储返回epoll事件的内容
    char buf[MAXLINE]; 
    struct sockaddr_storage client_addr;
    if(argc < 2) {
        app_error("Useage <port>");
    }
    listen_fd = open_listenfd(argvs[1]);
    if(listen_fd < 0) {
        app_error("open listen fd fail");
    }
    // efd = epoll_create(1);
    // clientaddr_len = sizeof(client_addr);
    // events = calloc(MAX_EVENTS, sizeof(event));
    // event.data.fd = listen_fd;
    // event.events = EPOLLIN | EPOLLET; // 这里用边缘触发，否则子进程accept前会一直触发
    // if(epoll_ctl(efd, EPOLL_CTL_ADD, listen_fd, &event) < 0) { //父进程中监听listen句柄
    //     perror("ctl add event failed");
    //     return EXIT_FAILURE;
    // }
    aeEventLoop *el = aeCreateEventLoop(1024);
    aeCreateFileEvent(el, listen_fd, AE_READABLE, NULL, NULL);
    aeMain(el);
    while(1) {
        event_count = epoll_wait(efd, events, MAX_EVENTS, -1);
        if(event_count < 0 && errno != EINTR) {
            perror("epoll wait error");
            break;
        }
        printf("wake up from epoll wait\n");
        for(i = 0; i < event_count; i++) {
            if((events[i].events & EPOLLERR) 
            | (events[i].events & EPOLLHUP)
            | !(events[i].events & EPOLLIN)) { //除了有新的内容可以读之外都忽略掉
                continue;
            } else if(events[i].data.fd == listen_fd) { //监听句柄有内容
                // 新的连接请求来了
                client_fd = Accept(listen_fd, (struct sockaddr *)&client_addr, (socklen_t *)&clientaddr_len);
                printf("pid %d accept %d\n", getpid(), client_fd);
                getnameinfo((const struct sockaddr *)&client_addr, sizeof(client_addr), client_host, 256, client_port, 256, 0);
                printf("connect <%s>:<%s>\n", client_host, client_port);
                struct epoll_event ee = {0};
                ee.events = 0;
                ee.data.fd = client_fd;
                ee.events = EPOLLIN | EPOLLET; // 加上边缘触发的目的是什么
                if(epoll_ctl(efd, EPOLL_CTL_ADD, client_fd, &ee) == -1) {
                    perror("ctl add event failed");
                    printf("%d\n", client_fd);
                    return EXIT_FAILURE;
                }
            } else {
                client_fd = events[i].data.fd;
                char buf[256];
                int count = read(client_fd, buf, 256);
                if (count == -1) {
                    if(errno != EAGAIN) {
                        perror("read error");
                        return EXIT_FAILURE;
                    }
                }
                if (count == 0) {
                    // 直接close么，不用epoll ctl然后 EPOLL_CTL_DEL么？
                    close(client_fd);
                }
                printf("client echo: %s", buf);
                // write 这里就必须是阻塞的了？
                write(client_fd, buf, strlen(buf));
            }
        }
    }
    free(events);
    Close(listen_fd);
    Wait(NULL);
    return 0;
}