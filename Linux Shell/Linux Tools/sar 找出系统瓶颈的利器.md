##  sar 找出系统瓶颈的利器

sar 是 System Activity Reporter（系统活动情况报告）的缩写。sar 工具将对系统当前的状态进行取样，然后通过计算数据和比例来表达系统的当前运行状态。

* 追溯过去的统计数据(默认)
* 周期性的查看当前数据

> 查看平均负载

`sar -q`: 查看平均负载

> 查看内存使用情况

`sar -r`：查看物理内存的使用情况

> 查看 CPU 使用率

`sar -u`：默认情况下显示 CPU 使用率

## 安装

Linux 系统下，默认可能没有安装这个包，使用 `apt-get install sysstat` 来安装；

安装完毕，将性能收集工具的开关打开：`vi /etc/default/sysstat`；设置 `ENABLED=”true”`

启动这个工具来收集系统性能数据：`/etc/init.d/sysstat start`
