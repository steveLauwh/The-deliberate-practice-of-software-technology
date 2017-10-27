## strace 跟踪系统调用和信号传递

strace 命令是一个集诊断、调试、统计与一体的工具，我们可以使用 strace 对应用的系统调用和信号传递的跟踪结果来对应用进行分析，
以达到解决问题或者是了解应用工作过程的目的。

### 跟踪系统调用

一个可执行文件 test，用 strace 调用执行：`strace ./test`

可以看到程序完整的执行过程。

### 跟踪信号传递

一个可执行文件 test，用 strace 调用执行：`strace ./test`

另一个窗口，执行：`killall test`

strace 中的结果显示 test 进程 `+++ killed by SIGTERM +++`。

### 统计系统调用

`strace -c ./test`，可以看出使用哪些系统调用和次数。

### 其它常用选项

```
-c  统计每一系统调用的所执行的时间,次数和出错的次数等

-t  在输出中的每一行前加上时间信息

-p  pid 跟踪指定的进程 pid

-o filename 将 strace 的输出写入文件 filename

....

```

## 参考

* [strace 命令](http://man.linuxde.net/strace)
