## Shell 数组

bash 只支持一维数组，没有限定数组的大小。数组元素的下标从 0 开始。

定义数组：`数组名=(值1 值2 ... 值n)`

读取数组元素：`${数组名[下标]}`

获取数组的所有元素：`${数组名[@]}` 或者 `${数组名[*]}`

获取数组的长度：`${#数组名[@]}` 或者 `${#数组名[*]}`

获取数组单个元素的长度：`${#数组名[下标]}`

Shell 实例：

```shell
#!/bin/bash

#定义 studentInfo 数组

studentInfo=(
steve
Lau
25
180
"Football"
)

echo "First Name: ${studentInfo[0]}"   #第一个元素

echo "Last Name: ${studentInfo[1]}"    #第二个元素

echo "Age: ${studentInfo[2]}"          #第三个元素

echo "Height: ${studentInfo[3]}"       #第四个元素

echo "Hobby: ${studentInfo[4]}"        #第五个元素

echo "Student Info: ${studentInfo[*]}" #获取数组中的所有元素

echo "Student Info: ${studentInfo[@]}" #获取数组中的所有元素

echo "Number：${#studentInfo[*]}"      #获取数组的长度

echo "Number: ${#studentInfo[@]}"      #获取数组的长度

i=2

echo ${studentInfo[i]}  #打印数组索引为 2 的元素

#定义数组另外一种方式

teacherInfo[0]=Wang

teacherInfo[1]=Yi

teacherInfo[2]=30

teacherInfo[3]=188

teacherInfo[4]="Basketball"

echo ${teacherInfo[*]}   #获取数组的所有元素

echo ${#teacherInfo[*]}  #获取数组的长度
```
