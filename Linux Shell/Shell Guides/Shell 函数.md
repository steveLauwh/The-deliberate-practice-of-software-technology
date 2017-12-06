## Shell 函数

```shell
[ function ] funname [()]

{

    action;

    [return int;]

}
```

函数实例
```shell
#!/bin/bash

fun()
{
    echo "第一个参数: $1"
    echo "第二个参数: $2"
    echo "第三个参数: $3"
    echo "第四个参数: $4"
    echo "第五个参数: $5"
    echo "第六个参数: $6"
    echo "参数的个数: $#"
    echo "输出所有的参数: $*"
}

fun 1 2 3 4 5 6
```

