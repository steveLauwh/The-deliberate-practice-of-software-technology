## Tenth Line「LeetCode 195」

题目：打印一个文件的第十行

```
How would you print just the 10th line of a file?

For example, assume that file.txt has the following content:

Line 1
Line 2
Line 3
Line 4
Line 5
Line 6
Line 7
Line 8
Line 9
Line 10
Your script should output the tenth line, which is:
Line 10
[show hint]

Hint:
1. If the file contains less than 10 lines, what should you output?
2. There's at least three different solutions. Try to explore all possibilities.
```

awk 是强大的文本分析工具，具有流控制、数学运算、进程控制、内置的变量和函数、循环和判断的功能。

其中 NR 表示行数，$0 表示当前记录
