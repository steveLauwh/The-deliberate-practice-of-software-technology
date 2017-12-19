## sed 命令

格式：

sed [选项] '[动作]' 文件名

选项：

-n或--quiet或——silent：仅显示 script 处理后的结果；

-i ：用 sed 的修改结果直接修改读取数据的文件，而不是由屏幕输出

-e ：允许对输入数据应用多余 sed 命令编辑

动作：

c ：行替换

i ：插入

d ：删除整行

p ：打印

s ：字符替换

```shell
// -n 选项和 p 命令一起使用表示只打印那些发生替换的行
sed -n 's/test/TEST/p' test.txt

// 查看文件的第二行
sed -n '2p' test.txt

// 全面替换 g
sed 's/test/TEST/g' test.txt

// 删除空白行
sed '/^$/d' file

// 删除第 2 行
sed '2d' file

// 删除文件最后一行
sed '$d' file
```
