进程标识（Process Identifiers）

- pid： 0和1 是内核的，0是swapper （scheduler process），1是init process（mac 中对应的launchd process /sbin/launch），在操作系统启动的时候内核调用，对应/sbin/init 管理 /etc/rc* huozhe1 /etc/inittab 还有 /etc/init.d 中的文件。pid每个进程唯一，死掉的可以reuse，但一组进程死掉的pid不会立即被reuse。
- effective user id 和 effective group id 控制进程打开所有文件的权限（默认和user id 和 group id 相同）


***
问题
* [ ] user process 和 system process 有什么区别，为什么init 进程不是system process
* [ ] 只有root打开的进程才能修改effective user id 和 effective group id么