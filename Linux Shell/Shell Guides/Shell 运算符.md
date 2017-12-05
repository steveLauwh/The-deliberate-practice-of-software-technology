## Shell 运算符

* 表达式和运算符之间要有空格
* 完整的表达式要被 ` ` 包含，注意这个字符不是常用的单引号

expr 是一款表达式计算工具，使用它能完成表达式的求值操作。

使用 if 判断，条件表达式需要放在方括号之间，并且两边都要有空格，如 `if [ $a == $b ]`。

### 算术运算符

```shell
#!/bin/bash

a=10

b=20

val=`expr $a + $b`   #加法
echo "a + b : $val"

val=`expr $a - $b`   #减法
echo "a - b : $val"

val=`expr $a \* $b`  #乘法
echo "a * b : $val"

val=`expr $b / $a`   #除法
echo "b / a : $val"

val=`expr $b % $a`   #求余
echo "b % a : $val"

if [ $a == $b ]      #判断，条件表达式要放在方括号之间，并且要有空格
then
    echo "a 等于 b"
fi

if [ $a != $b ]
then
    echo "a 不等于 b"
fi
```

### 关系运算符

```shell
#!/bin/bash

a=10

b=20

if [ $a -eq $b ]
then
    echo "$a -eq $b : a 等于 b"
else
    echo "$a -eq $b : a 不等于 b"   
fi

if [ $a -ne $b ]
then
    echo "$a -ne $b : a 不等于 b"
else
    echo "$a -ne $b : a 等于 b"
fi

if [ $a -gt $b ]
then
    echo "$a -gt $b : a 大于 b"
else
    echo "$a -gt $b : a 不大于 b"
fi

if [ $a -lt $b ]
then
    echo "$a -lt $b : a 小于 b"
else
    echo "$a -lt $b : a 不小于 b"
fi

if [ $a -ge $b ]
then
    echo "$a -ge $b : a 大于或等于 b"
else
    echo "$a -ge $b : a 小于 b"
fi

if [ $a -le $b ]
then
    echo "$a -le $b : a 小于或等于 b"
else
    echo "$a -le $b : a 大于 b"
fi
```

### 布尔运算符

`-a` 表示与运算

`-o` 表示或运算

```shell
#!/bin/bash

a=10

b=20

if [ $a != $b ]
then
    echo "$a != $b : a 不等于 b"
else
    echo "$a != $b : a 等于 b"
fi

if [ $a -lt 100 -a $b -gt 15 ]
then
    echo "$a 小于 100 且 $b 大于 15 : 返回 true"
else
    echo "$a 小于 100 且 $b 大于 15 : 返回 false"
fi

if [ $a -lt 100 -o $b -gt 100 ]
then
    echo "$a 小于 100 或 $b 大于 100 : 返回 true"
else
    echo "$a 小于 100 或 $b 大于 100 : 返回 false"
fi

if [ $a -lt 5 -o $b -gt 100 ]
then
    echo "$a 小于 5 或 $b 大于 100 : 返回 true"
else

    echo "$a 小于 5 或 $b 大于 100 : 返回 false"
fi
```

### 逻辑运算符

```shell
#!/bin/bash

a=10

b=20

if [[ $a -lt 100 && $b -gt 100 ]]
then
    echo "返回 true"
else
    echo "返回 false"
fi

if [[ $a -lt 100 || $b -gt 100 ]]
then
    echo "返回 true"
else
    echo "返回 false"
fi
```

### 字符串运算符

```shell
#!/bin/bash

a="steve"

b="Lau"

if [ $a = $b ]
then
    echo "$a = $b : a 等于 b"
else
    echo "$a != $b : a 不等于 b"
fi

if [ $a != $b ]
then
    echo "$a != $b : a 不等于 b"
else
    echo "$a == $b : a 等于 b"
fi

if [ -z $a ]
then
    echo "-z $a : 字符串长度为 0"
else
    echo "-z $a : 字符串长度不为 0"
fi

if [ -n $a ]
then
    echo "-n $a : 字符串长度不为 0"
else
    echo "-n $a : 字符串长度为 0"
fi

if [ $a ]
then
    echo "$a : 字符串不为空"
else
    echo "$a : 字符串为空"
fi
```

### 文件测试运算符

文件测试运算符用于检测 `*nix` 文件的各种属性。

```shell
#!/bin/bash

file="./test.sh"

if [ -r $file ]
then
   echo "文件可读"
else
   echo "文件不可读"
fi

if [ -w $file ]
then
    echo "文件可写"
else
    echo "文件不可写"
fi

if [ -x $file ]
then
    echo "文件可执行"
else
    echo "文件不可执行"
fi

if [ -f $file ]
then
    echo "文件为普通文件"
else
    echo "文件为特殊文件"
fi

if [ -d $file ]
then
    echo "文件是个目录"
else
    echo "文件不是个目录"
fi

if [ -s $file ]    
then
    echo "文件不为空"
else
    echo "文件为空"
fi

if [ -e $file ]
then
    echo "文件存在"
else
    echo "文件不存在"
fi
```

