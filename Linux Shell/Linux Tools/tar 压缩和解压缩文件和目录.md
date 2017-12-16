## tar 压缩和解压缩文件和目录

```shell
tar -cvf xxx.tar xxx/    // 打包，不压缩，创建一个 tar 文件

tar -xvf xxx.tar   // 解压 tar 文件

tar -tvf xxx.tar  // 查看 tar 文件

tar -jcvf xxx.tar.bz2 xxx  // 压缩bz2

tar -zcvf xxx.tar.gz  xxx  // 压缩gz

tar -jxvf xxx.tar.bz2   // 解压缩bz2

tar -zxvf xxx.tar.gz    // 解压缩gz
```

压　缩：tar -jcvf filename.tar.bz2 要被压缩的文件或目录名称
查　询：tar -jtvf filename.tar.bz2 
解压缩：tar -jxvf filename.tar.bz2 -C 欲解压缩的目录   // root环境下

## gzip 压缩文件

```shell
gzip xxx   // 创建一个 *.gz 的压缩文件

gzip -d xxx.gz // 解压 *.gz 文件

gzip -l xxx.gz // 显示压缩的比率
```

## bzip2

用于创建和管理（包括解压缩）“.bz2”格式的压缩包

```shell
bzip2 xxx  // 创建 *.bz2 压缩文件

bzip2 -d xxx.bz2  // 解压 *.bz2 文件
```

## unzip

```shell
uzip xxx.zip // 解压 *.zip 文件

unzip -l xxx.zip  // 查看 *.zip 文件的内容
```
