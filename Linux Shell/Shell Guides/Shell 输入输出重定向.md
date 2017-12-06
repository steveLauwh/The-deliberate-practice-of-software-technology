## Shell 输入/输出重定向

### 输出重定向

```shell
#执行 command1 然后将输出的内容存入 file1，file1 原有的内容会被覆盖
command1 > file1
```

如果不希望文件内容被覆盖，可以使用 >> 追加到文件末尾。

```shell
#执行 command1 然后将输出的内容存入 file1，file1 原有的内容不会被覆盖
command1 >> file1
```

### 输入重定向

```shell
command1 < file1
```

```shell
#执行 command1，从文件 infile 读取内容，然后将输出写入到 outfile 中
command1 < infile > outfile
```

### 标准输入输出的重定向

* 标准输入文件(stdin)：stdin 的文件描述符为 0，Unix/Linux 程序默认从 stdin 读取数据。
* 标准输出文件(stdout)：stdout 的文件描述符为 1，Unix/Linux 程序默认向 stdout 输出数据。
* 标准错误文件(stderr)：stderr 的文件描述符为 2，Unix/Linux 程序会向 stderr 流中写入错误信息。

默认情况下，command > file 将 stdout 重定向到 file，command < file 将 stdin 重定向到 file。

```shell
command 2 > file  #stderr 重定向到 file

command 2 >> file #stderr 追加到 file 文件末尾

#放在>后面的&，表示重定向的目标不是一个文件，而是一个文件描述符
command > file 2>&1 #将 stdout 和 stderr 合并后重定向到 file
```
