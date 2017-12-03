## Transpose File「LeetCode 194」

转置，行和列转换

```
Given a text file file.txt, transpose its content.

You may assume that each row has the same number of columns and each field is separated by the ' ' character.

For example, if file.txt has the following content:

name age
alice 21
ryan 30
Output the following:

name alice ryan
age 21 30
```

NF 表示当前记录中的字段个数，就是有多少列

NR 表示已经读出的记录数，就是行号，从 1 开始

i 实际上遍历的数字为 1,2,1,2,1,2

