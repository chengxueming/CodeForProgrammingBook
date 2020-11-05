```sh
[cxm@study nginx]$ sudo tcpdump host 192.168.1.43 and not port 22
tcpdump: verbose output suppressed, use -v or -vv for full protocol decode
listening on enp0s3, link-type EN10MB (Ethernet), capture size 262144 bytes
13:46:57.208598 IP 192.168.1.43.62533 > study.centos.vbird.http: Flags [S], seq 2736282364, win 65535, options [mss 1460,nop,wscale 6,nop,nop,TS val 827634354 ecr 0,sackOK,eol], length 0
13:46:57.208663 IP study.centos.vbird > 192.168.1.43: ICMP host study.centos.vbird unreachable - admin prohibited, length 72
```

[iptables](https://wangchujiang.com/linux-command/c/iptables.html#%E9%80%89%E9%A1%B9)