#include<stdio.h>

typedef enum months { JAN = 1, FEB, MAR, APR } MONTH;
int my_strlen(char s[]) {
    int i;
    i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    return i;
}

int main() {
    //printf("%s", "hello " "world" "\0141");
    MONTH i = FEB;
    switch(i) {
        case JAN:
            printf("hhh");
            break;
        case FEB:
            printf("bbbb");
            break;
    }
    printf("%d\n", my_strlen("abcdef"));
    return 1;
}