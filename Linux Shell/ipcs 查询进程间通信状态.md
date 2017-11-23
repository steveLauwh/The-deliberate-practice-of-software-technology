## ipcs 查询进程间通信状态

ipcs 是 Linux 下显示进程间通信设施状态的工具。可以显示消息队列、共享内存和信号量的信息。

> 查看系统使用的 IPC 资源

`ipcs`

> 分别查询 IPC 资源

```
ipcs -m 查看系统使用的 IPC 共享内存资源
ipcs -q 查看系统使用的 IPC 队列资源
ipcs -s 查看系统使用的 IPC 信号量资源
```

> 系统 IPC 参数查询

```
ipcs -l
```

> 查看 IPC 资源被谁占用

已知 IPC KEY，把它转换为十六进制 xxx

`ipcs -m | grep xxx`

> 修改 IPC 系统参数

在 root 用户下修改 `/etc/sysctl.conf` 文件，保存后使用 `sysctl -p` 生效。



