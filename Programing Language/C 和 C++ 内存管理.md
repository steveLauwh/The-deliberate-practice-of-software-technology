## C/C++ 内存管理

内存的本质是资源，操作系统管理内存资源，那么申请和归还内存资源就是内存管理。

### C 内存管理

malloc 和 free

```c
void *malloc(unsigned int num_bytes);

void free(void *memblock);
```

### C++ 内存管理

new 和 delete

申请和释放内存的方法：

```c++
int *p = new int;

delete p;
```

申请和释放块内存的方法：

```c++
int *arr = new int[10];

delete[] arr;
```

释放内存注意事项：

```c++
int *p = new int;
if (NULL == p)
{
    // 内存分配失败，异常处理
}

delete p;
p = NULL;
```

```c++
int *p = new int[1000];
if (NULL == p)
{
    // 内存分配失败，异常处理
}

delete[] p;
p = NULL;
```

申请内存需要判断是否成功，释放内存需要设空指针。
