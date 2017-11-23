## top Linux 下的任务管理器

top 命令是 Linux 下常用的性能分析工具，能够实时显示系统中各个进程的资源占用状况，类似于 Windows 的任务管理器。

top 命令交换操作指令：

* P 按 %CPU 使用率排行
* T 按 TIME+ 排行
* M 按 %MEM 排行

> 显示完整的程序指令

`top -c`

> 显示指定的进程信息

`top -p pidid`

## 更强大的工具 htop

htop 是一个 Linux 下的交互式的进程浏览器，可以用来替换 Linux 下的 top 命令。
