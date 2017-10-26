## 定位内存泄露(memory leak)

内存泄露：在编写代码时因疏忽或代码编写不当而造成程序中不再使用的内存未能及时释放的情况。

内存泄露大致可分为常发性、偶发性、一次性和隐式内存泄露四种。

解决内存泄露的主要手段：

* 良好的代码习惯
* 重载 new 和 delete
* 使用相关的软件进行辅助查找，如 Valgrind

### Valgrind 工具

Valgrind 是一套 Linux 下，开放源代码(GPL V2)的仿真调试工具的集合。

Valgrind 包含以下工具：

* Memcheck：应用最广泛的工具，一个重量级的内存检查器
* Callgrind：主要用来检查程序中函数调用过程中出现的问题
* Cachegrind：主要用来检查程序中缓存使用出现的问题
* Helgrind：主要用来检查多线程程序中出现的竞争问题
* Massif：主要用来检查程序中堆栈使用中出现的问题
* Extension：可以利用 core 提供的功能，自己编写特定的内存调试工具

在 Ubuntu 下安装 Valgrind：`apt-get install valgrind`。

> **Memcheck 内存检查器的选项**

`--leak-check=<no|summary|yes|full> [default:summary]`

* 用于控制内存泄露的检查力度
* No，不检测内存泄露
* Summary，仅报告总共泄露的数量，不显示具体泄露位置
* Yes/full，报告泄露总数以及泄露的具体位置

`--show-reachable=<yes|no> [default:no]`

* 用于控制是否检测控制范围之外的泄露，例如全局指针，static 指针等
* No，不检测

`--undef-value-errors=<yes|no> [default:yes]`

* 用于控制是否检测代码中未初始化变量的使用情况
* No，不报告错误

`--log-file=filename`

* 用于将 log 信息输出到文件

`--log-socket=192.168.0.1:12345`

* 用于将 log 信息输出到网络

`--trace-children=<yes|no> [defalut:no]`

* 追踪子进程

> **Memcheck 内存检查器的原理**

关键在于建立了两个全局表：Valid-Value 表和 Valid-Address 表。

* Valid-Value 表：对于进程整个地址空间中的每一个字节(Byte)，都有与之对应的 8 bit；对于 CPU 的每个寄存器，也有一个与之对应的 bit 向量。
这些 bit 负责记录该字节或者寄存器值是否具有有效的、已初始化的值。
* Valid-Address 表：对于进程整个地址空间中的每一个字节(Byte)，都有与之对应的 1 bit，负责记录该地址是否能够被读写。

检查原理：当要读写内存中某个字节时，首先检查这个字节对应的 A bit。如果该 A bit 显示该位置是无效位置，Memcheck 则报告读写错误。

> **Valgrind 使用**

Valgrind 默认的工具就是 Memcheck，可以通过 `--tool=tool name` 指定其它的工具。

为了使 Valgrind 发现的错误更加精确，在编译时加上 `-g` 参数。

```
g++ -g -o test test.cpp

valgrind --tool=memcheck ./test
```

使用 Valgrind 检查常见的内存错误

* 使用未初始化的内存
* 在内存被释放后进行读/写
* 内存读写越界(从已分配内存块的尾部进行读/写)
* 内存覆盖(如 strcpy、strncpy、memcpy、strcat)
* 内存泄露
* 动态内存管理错误(不匹配地使用 malloc/new/new[] 和 free/delete/delete[])
* 两次释放内存



