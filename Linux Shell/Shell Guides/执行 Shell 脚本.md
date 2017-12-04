## 执行 Shell 脚本

Linux Shell 的类型有多种，这里使用 Bourne Again Shell（/bin/bash），简称 Bash Shell。

例如：hello.sh

```shell
#!bin/bash

echo "Hello World!"
```

运行 Shell 脚本有两种方法：

1.切换到脚本目录

```
chmod +x hello.sh  #加上执行权限
./hello.sh         #执行脚本
```

2.使用解释器执行

```
/bin/bash hello.sh
```

特别注意：

当第一行`#!/bin/bash`，少写了一个 /，会导致 bin/bash: 解释器错误: 没有那个文件或目录。

