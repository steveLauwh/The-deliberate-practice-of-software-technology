## vmstat 监视内存使用情况

vmstat 是 Virtual Meomory Statistics（虚拟内存统计）的缩写，可实时动态监视操作系统的虚拟内存、进程、CPU 活动。

* -V 表示打印出版本信息
* -n 表示在周期性循环输出时，输出的头部信息仅显示一次
* delay 是两次输出之间的延迟时间
* count 是指按照这个时间间隔统计的次数

Procs（进程）:
r: 运行队列中进程数量
b: 等待 IO 的进程数量
