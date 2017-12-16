## find 查找文件

find 用于在指定目录下查找文件。

```shell
find -iname "*.txt"  // 忽略大小写，查找以 .txt 结尾的文件名

find -iname "coremain.cpp" -exec md5sum {} \; // 借助 -exec 选项与其他命令结合使用 

find ~ -empty  // 查找 home 目录下的所有空文件
```
