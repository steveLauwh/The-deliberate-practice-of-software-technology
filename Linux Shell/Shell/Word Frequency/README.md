## Word Frequency「LeetCode 192」

题目：词频

```
Write a bash script to calculate the frequency of each word in a text file words.txt.

For simplicity sake, you may assume:

words.txt contains only lowercase characters and space ' ' characters.
Each word must consist of lowercase characters only.
Words are separated by one or more whitespace characters.
For example, assume that words.txt has the following content:

```
```
the day is sunny the the
the sunny is is
```
```
Your script should output the following, sorted by descending frequency:

the 4
is 3
sunny 2
day 1
```

grep 命令

-oE '[a-z]+' 参数表示原文本内容变成一个单词一行的存储方式

sort -nr 表示按数值进行降序排列

uniq -c 参数表示去除重复行命令，并且每行前加上出现次数






