# 常用 C 库函数

## 复制

### memcpy

作用：Copy block of memory

```c
#include <string.h>

void *memcpy(void *dest, const void *src, size_t n);
```

### memmove

作用：Move block of memory

```c
#include <string.h>

void *memmove(void *dest, const void *src, size_t n);
```

### strcpy 

作用：Copy string

```c
#include <string.h>

char *strcpy(char *dest, const char *src);
```

### strncpy

作用：Copy characters from string

当 src 指向字符串中包含 `\0` 字符，strncpy 遇到 `\0`，就会停止拷贝。

手动填 '\0'

```c
#include <string.h>

char *strncpy(char *dest, const char *src, size_t n);
```

## 字符串连接

### strcat

作用：将 src 指向字符串连接到 dest

```c
#include <string.h>

char *strcat(char *dest, const char *src);
```

### strncat

作用：把 src 前 n 个字符连接到 dest

```c
#include <string.h>

char *strcat(char *dest, const char *src, size_t n);
```

## 比较

### memcmp

```c
#include <string.h>

int memcmp(const void *s1, const void *s2, size_t n);
```

### strcmp

作用：比较两个字符串。

```c
#include <string.h>

int strcmp(const char *s1, const char *s2);  
```

### strncmp

作用：比较两个字符串的前 n 个字符

```c
#include <string.h>

int strncmp(const char *s1, const char *s2, size_t n);
```

## 查找

### strstr

作用：在字符串1中查找字符串2，返回字符串2在字符串1第一次出现位置

```c
#include <string.h>

char *strstr(const char *haystack, const char *needle);
```

## 其它

### memset

作用：fill memory with a constant byte，一般用于内存初始化

```c
#include <string.h>

void *memset(void *s, int c, size_t n);
```

### strerror

作用：返回错误码

```c
#include <string.h>

char *strerror(int errnum);
```

### strlen

作用：求字符串的长度

```c
#include <string.h>

size_t strlen(const char *s);
```

## 参考

* [C library](http://www.cplusplus.com/reference/clibrary/)
