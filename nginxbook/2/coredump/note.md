
## 临时修改ulimit 和 core_pattern
```sh
ulimit -c unlimited # 临时的 永久的要修改 /etc/security/limits.conf 
echo /usr/core_log/core_%e_%t_%p > /proc/sys/kernel/core_pattern #目录要提前建好 需要root权限
```

## 永久修改
- 修改/etc/security/limits.conf, 设置ulimit（需要reboot）
  ```
  @root soft core unlimited
  @root hard core unlimited
  ```
- 修改/etc/sysctl.conf，设置core_pattern(需要sysctl –p) 
  ```
  kernel.core_pattern = /var/core_log/core_%e_%t_%p
  kernel.core_uses_pid = 0
  ```
## 使用
```sh
[root@study bin]# gdb ./core_prog
(gdb) core-file  /usr/core_log/core_core_prog_1603948990_2631
(gdb) where
```

## 问题
- [ ] ulimit 是对于某个用户生效，还是某个session生效？

## 参考
- [gdb调试coredump(使用篇)
](https://blog.csdn.net/sunxiaopengsun/article/details/72974548)

- [linux core文件位置
](https://www.cnblogs.com/banwhui/p/5192592.html)