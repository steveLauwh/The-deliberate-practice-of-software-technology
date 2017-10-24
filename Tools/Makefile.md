## Makefile 文件

### Makefile 是什么，其作用？

大型工程项目的文件巨多，makefile 定义了一系列规则来指定那些文件先编译，那些文件后编译等，编写好 Makefile 后，只需要一个 make 命令，就可以整个工程完全自动编译，极大地提高了软件开发的效率。

### Makefile 的规则

```makefile
target ... : prerequisites ...
    command
    ...
    ...
```

* target - 目标文件, 可以是 Object File, 也可以是可执行文件
* prerequisites - 生成 target 所需要的文件或者目标
* command - make 需要执行的命令 (任意的shell命令), Makefile 中的命令必须以 [tab] 开头

### Makefile 的一个简单例子

假设一个工程包括 a.cpp、b.cpp、c.cpp、a.h、b.h、c.h 这些文件，makefile 文件如下：

```makefile
dodo ：a.o b.o c.o
    g++ a.o b.o c.o -o dodo

a.o : a.cpp a.h
    g++ -c a.cpp a.h -o a.o

b.o : b.cpp b.h
    g++ -c b.cpp b.h -o b.o

c.o : c.cpp c.h
    g++ -c c.cpp c.h -o c.o

clean:
    rm -rf *.o dodo
```

继续演进，makefile 中使用变量

```makefile
OBJS = a.o b.o c.o
TARGET = dodo
CXX = g++

$(TARGET) ：$(OBJS)
    $(CXXCXXCXXCXX) $^ -o $@

a.o : a.cpp a.h
    $(CXXCXXCXX) -c $< -o $@

b.o : b.cpp b.h
    $(CXXCXX) -c $< -o $@

c.o : c.cpp c.h
    $(CXX) -c $< -o $@

.PHONY : clean
clean :
    -rm $(TARGET) $(OBJS)
```

### Makefile 的一些特性

* = 和 := 的区别在于, := 只能使用前面定义好的变量, = 可以使用后面定义的变量
* 只有行注释 `#`，如果要使用或者输出 "#" 字符, 需要进行转义, "\#"
* command 太长, 可以用 `\` 作为换行符
* $@ --代表目标文件(target)
* $^ --代表所有的依赖文件(components)
* $< --代表第一个依赖文件(components中最左边的那个)。

.....

## 参考

* [跟我一起写 Makefile](http://scc.qibebt.cas.cn/docs/linux/base/%B8%FA%CE%D2%D2%BB%C6%F0%D0%B4Makefile-%B3%C2%F0%A9.pdf)
