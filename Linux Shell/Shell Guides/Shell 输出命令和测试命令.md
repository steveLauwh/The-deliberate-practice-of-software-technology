## echo 命令

用于字符串的输出。

echo 自动添加换行符。

```shell
#!/bin/bash

echo "I am a string"  #显示普通字符串，使用双引号

echo I am a string    #显示普通字符串，使用无引号

echo '$name\"'        #使用单引号，原样输出

echo "\"It is a string\"" #显示转义符

read name       #read 命令从标准输入中读取一行

echo "$name input" #输出

echo -e "OK! \n"   #-e 开启转义，\n 换行

echo "换行"        

echo -e "OK! \c"   #-e 开启转义，\c 不换行

echo "不换行"

echo "redirect the file" > file  #重定向至文件

echo `date`   #反引号，显示当前日期
```

## printf 命令

默认 printf 不会像 echo 自动添加换行符，需要手动添加 \n。

printf 可以使用格式化字符串，还可以制定字符串的宽度、左右对齐方式等。

%d %s %c %f 格式替代符详解:

* d: Decimal 十进制整数 -- 对应位置参数必须是十进制整数，否则报错！
* s: String 字符串 -- 对应位置参数必须是字符串或者字符型，否则报错！
* c: Char 字符 -- 对应位置参数必须是字符串或者字符型，否则报错！
* f: Float 浮点 -- 对应位置参数必须是数字型，否则报错！

```shell
!/bin/bash

echo "Hello World"

printf "Hello World\n"

printf "%-10s %-8s %-4s\n" 姓名 性别 体重kg

printf "%-10s %-8s %-4.2f\n" steve 男 65.122 #%-10s 指一个宽度为10个字符（-表示左对齐，没有则表示右对齐）

printf "%s %s %s\n" a b c d e f g t w 

printf %d 1 #没有引号，也可输出

printf '\n%d %s\n' 1 abc #单引号，也可输出
```

## test 命令

Shell 中的 test 命令用于检查某个条件是否成立，它可以进行数值、字符和文件三个方面的测试。

```shell
#!/bin/bash

a=100

b=200

if test $[a] -eq $[b]    #数值测试
then 
    echo "a 和 b 相等"
else
    echo "a 和 b 不相等"
fi

if test $[a] -lt $[b]
then
    echo "a 小于 b"
else
    echo "a 大于 b"
fi

str1="abc"

str2="def"

if test $str1 = $str2  #字符串测试
then
    echo "str1 和 str2 字符串相等"
else
    echo "str1 和 str2 字符串不相等"
fi

if test -e ./file  #文件测试
then
    echo "文件存在"
else
    echo "文件不存在"
fi
```
