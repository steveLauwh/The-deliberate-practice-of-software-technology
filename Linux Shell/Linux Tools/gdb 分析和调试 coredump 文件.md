## gdb 分析和调试 coredump 文件

### 设置 coredump 文件大小

默认 ubuntu 是不会产生 core 文件，可以通过 `ulimit -c unlimited` 来设置，该命令是设置 core 文件大小不受限。

但是只针对当前会话有效。如果要系统生效，在 `/etc/profile` 中添加 `ulimit -c unlimited` 这行，然后 `system /etc/profile` 生效配置。

```
// 表示不会产生 core 文件
ulimit -c 0 
  
// 表示 core 文件最大为 100 blocks(1 blocks = 512字节)
ulimit -c 100
```

### coredump 文件的存储位置

默认情况下，core 文件的存储位置与当前可执行程序的位置是在同一目录，文件名为 core。

如果修改产生 core 文件的存储位置，需要操作如下：

`vim /etc/sysctl.conf`，加入两行

```
kernel.core_pattern = /data/coredump/core_%e_%p
kernel.core_uses_pid = 0
```
`sysctl –p /etc/sysctl.conf`，修改生效。

产生 core 文件，保存在 `/data/coredump` 目录下。

### 不会生成 coredump 文件

* 当前进程是用户ID，但是当前用户不是程序的所用者
* 当前进程是组ID，但是当前用户不是程序的组所用者
* 用户没有写当前工作目录的许可权
* 文件太大，core 文件的许可权(假定该文件在此之前并不存在)通常是用户读/写，组读和其他读。

### 例子

```c++
// CoreTest.cpp
#include <stdio.h>

void coreTest()
{
    char *test = "HelloWorld";
    *test = 0;
}

int main()
{
    coreTest();
    return 0;
}
```

* `g++ -g CoreTest.cpp -o CoreTest`
* `./CoreTest`，会产生段错误，当前目录生成 core 文件
* `gdb CoreTest core`，调试 core 文件，进入 gdb，输入 `bt`，查看当前运行的堆栈列表，可以查看程序出错那行

最后进入 gdb 环境，打断点调试。

段错误：产生 signal

* SIGSEGV：11，指示进程进行了一次无效的存储访问
* SIGFPE：8，此信号表示一个算术运算异常
