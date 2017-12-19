## awk 命令

格式：

awk '条件1{动作1} 条件2{动作2}...' 文件名

```shell
// 打印 test.txt 文件中第2和第4列
awk '{printf $2 "\t" $4 "\n"}' test.txt

// df -h 用来查看Linux服务器的文件系统的磁盘空间占用情况，用 awk 查看第1和第4列
df -h | awk '{print $1, $4}'

df -h | grep "/dev/sda4" | awk '{print $5}' | cut -d "%" -f 1
```
