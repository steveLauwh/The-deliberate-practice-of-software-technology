## Shell 字符串

字符串可以用单引号表示，也可以用双引号表示。

注意单双引号的区别，双引号可以包括变量，转义字符。

掌握字符串的截取功能。

```shell
#!/bin/bash

str_one='This is First String!'   #字符串使用单引号表示

echo $str_one

str_two="This is Two String!"     #字符串使用双引号表示
    
str_three="include \"$str_two\""  #双引号字符串可以有变量和转义字符

echo $str_three

name="steve Lau"

greeting="Hello, "$name" !"  #拼接字符串

other="Hello, ${name} !"

echo $greeting

echo $other

echo ${#greeting}   #获取字符串长度

echo ${greeting:1:4}  #提取子字符串

echo `expr index "$greeting" st`  #查找子字符串 st 位置

url="https://github.com/index.html"

echo ${url#*//}   #一个 # 表示从左边删除到第一个指定的字符

echo ${url##*/}   #两个 # 表示从左边删除到最后一个指定的字符

echo ${url%/*}    #一个 % 表示从右边删除到第一个指定的字符

echo ${url%%/*}   #两个 % 表示从右边删除到最后一个指定的字符

echo ${url:0:5}   #从左边第1个字符开始，5表示字符的总个数

echo ${url:7}     #从左边第8个字符开始，一直结束

echo ${url:0-7:3} #从右边第7个字符开始，3表示字符的总个数

echo ${url:0-7}   #从右边第7个字符开始，一直结束
```
