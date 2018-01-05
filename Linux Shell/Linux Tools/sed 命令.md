## sed 命令

sed: stream editor，一个非交互式文本编辑器。可以对文本文件和标准输入进行编辑。

sed 是专门设计用来处理文本编辑任务(增删查改)的程序。

### sed 基础语法

**格式：**

sed [选项] '[动作]' 文件名

**选项：**

-n或--quiet或——silent：仅显示 script 处理后的结果；

-i ：用 sed 的修改结果直接修改读取数据的文件，而不是由屏幕输出

-e ：允许对输入数据应用多余 sed 命令编辑

-r ：以正则表达式方式解析命令

**动作：**

c ：行替换

i ：在定址行之前插入

a ：在定址行之后添加

d ：删除整行

p ：打印

s ：字符替换

### sed 增删查改

cat test.txt

```shell
file1
test
test1
file2

file3

end
```

> **增加行**

在定址行之前插入：`sed '/end/ i insertLine' test.txt`

在定址行之后添加：`sed '/end/ a insertLine' test.txt`

直接修改文件：`sed -i '/end/ a insertLine' test.txt`

> **删除行**

```
// 删除空白行
sed '/^$/d' file

// 删除第 2 行
sed '2d' file

// 删除文件最后一行
sed '$d' file
```

> **修改行**

```
// 全面替换 g
sed 's/test/TEST/g' test.txt

// 将 end 修改为 rev
sed '/end/ c rev' test.txt
```

> **查看行**

```
// -n 选项和 p 命令一起使用表示只打印那些发生替换的行
sed -n 's/test/TEST/p' test.txt

// 查看文件的第二行
sed -n '2 p' test.txt
```
