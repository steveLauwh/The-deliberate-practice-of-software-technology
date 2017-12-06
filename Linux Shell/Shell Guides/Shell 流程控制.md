## Shell 流程控制

### if

```shell
if condition
then
    command1 
    command2
    ...
    commandN 
fi
```

```shell
if condition
then
    command1 
    command2
    ...
    commandN
else
    command
fi
```

```shell
if condition1
then
    command1
elif condition2 
then 
    command2
else
    commandN
fi
```

if 实例
```shell
#!/bin/bash

a=10

b=20

if [ $a == $b ]
then
    echo "a 等于 b"
elif [ $a -gt $b ]
then
    echo "a 大于 b"
elif [ $a -lt $b ]
then
    echo "a 小于 b"
else
    echo "noknown"
fi
```

### for

```shell
for var in item1 item2 ... itemN
do
    command1
    command2
    ...
    commandN
done
```
for 实例
```shell
#!/bin/bash

for loop in 1 2 3 4 5 6 
do
    echo "The value is $loop"
done

for str in "I am a string"
do
    echo $str
done
```

### while

```shell
while condition
do
    command
done
```
while 实例
```shell
#!/bin/bash

val=1

while(($val <= 5)) 
do
    echo $val
    let "val++"
done

while read str  #read读命令，ctrl+D 退出循环
do
    echo $str
done
```

```shell
#无限循环，可以使用 break 或 continue 跳出循环；两个关键字，与 C 语言功能一样
while :
do
    command
done
```

### case

```shell
case 值 in
模式1)
    command1
    command2
    ...
    commandN
    ;;
模式2）
    command1
    command2
    ...
    commandN
    ;;
esac
```
case 实例
```shell
#!/bin/bash

while :
do
    echo -n "输入 1-5 的数字: "
    
    read num 

    case $num in
        1|2|3|4|5)
            echo "数字为: $num"
            ;;  

        *)  
            echo "Over!"
            break
            ;;  
    esac
done
```

