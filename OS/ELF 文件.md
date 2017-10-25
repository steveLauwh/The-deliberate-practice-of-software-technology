## ELF 文件

ELF(Executable and Linkable Format)：是一种用于二进制文件、可执行文件、目标代码、共享库和核心转储的标准文件格式。

ELF 格式的文件用于存储 Linux 程序。

ELF 文件结构：`/usr/include/elf.h`

### ELF 的文件类型

* 可重定位的目标文件

文件保存着代码和适当的数据，用来和其他的目标文件一起来创建一个可执行文件或者一个共享目标文件。（目标文件或者静态库文件，即linux通常后缀为.a和.o的文件）

* 可执行的目标文件

文件保存着一个用来执行的程序。（例如bash，gcc等）

* 可被共享的目标文件

共享库。文件保存着代码和合适的数据，用来被下连接编辑器和动态链接器链接。（linux下后缀为.so的文件。）

### ELF 文件组成

一般的 ELF 文件包括三个索引表：ELF header，Program header table，Section header table。

ELF header：在文件的开始，保存了路线图，描述了该文件的组织情况。

Program Header Table：告诉系统如何创建进程映像。用来构造进程映像的目标文件必须具有程序头部表，可重定位文件不需要这个表。(可选)

Section Header Table：包含了描述文件节区的信息，每个节区在表中都有一项，每一项给出诸如节区名称、节区大小这类信息。(可选)

用于链接的目标文件必须包含节区头部表，其他目标文件可以有，也可以没有这个表。

### 阅读 ELF 文件的工具——readelf

`readelf -h xxx`：显示 xxx 文件的 ELF Header 的文件头信息(ELF 文件开始的前 52 Byte)。

`readelf -l xxx`：显示 xxx 文件的 Program Header Table 中的每个 Program Header Entry 的信息

`readelf -S xxx`：显示 xxx 文件的 Section Header Table 中的每个 Section Header Entry 的信息

`readelf -a xxx`：显示 xxx 的全部信息

### ELF section

在一个 ELF 文件中有一个 section header table，通过它我们可以定位到所有的 section，
而 ELF header 中的 e_shoff 变量就是保存 section header table 入口对文件头的偏移量。
而每个 section 都会对应一个 section header ，所以只要在 section header table 中找到每个 section header，
就可以通过 section header 找到你想要的 section。

section 是在 ELF 文件里头，用以装载内容数据的最小容器。

* .text section：装载可执行代码  `objdump -d -j .text xxx`
* .data section：装载被初始化的数据  `objdump -d -j .data xxx`
* .bss section：装载未被初始化的数据  
* .strtab section：装载字符串信息
* .symtab section：装载符号信息


