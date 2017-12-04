## Shell 变量

定义 Shell 变量名，需要遵循以下规则：

* 首个字符必须为字母(a-z，A-Z)
* 中间不能有空格，可以使用下划线
* 不能使用标点符号
* 不能使用 bash 里的关键字

定义一个变量 name 后，通过 `$` 使用，`$name` 或 `${name}`。

使用 readonly 命令，设置变量为只读。

使用 unset 命令，可以删除变量。

Shell 实例：

```shell
#!/bin/bash

name="steve Lau" #定义变量 name

echo $name  #打印 steve Lau

echo ${name} #打印变量，变量加上花括号，推荐

name="steve" #重新定义变量 name

echo ${name} #打印 steve

url="https://github.com"

readonly url #url 设置为只读变量

echo ${url}

# url="http://google.com" #报错，因为只读

unset name #删除变量 name

echo ${name} #没有任何输出
```
