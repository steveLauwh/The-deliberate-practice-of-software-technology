## iostat 监视 I/O 子系统

iostat 是 I/O statistics（输入/输出统计）的缩写，用来动态监视系统的磁盘操作活动。

通过 iostat 方便查看 CPU、网卡、tty设备、磁盘、CD-ROM 等等设备的活动情况, 负载信息。

命令格式：

iostat[参数][时间][次数]

如：每隔 2 秒刷新显示，且显示 3 次：`iostat 2 3`

tps：该设备每秒的传输次数(一次传输就是一次 I/O 请求)。

> 查看 TPS 和吞吐量

`iostat -d -k 1 1`
