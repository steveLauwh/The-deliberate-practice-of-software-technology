## 5. Virtual memory hardware

### 共享物理内存的问题

* Protection 防止进程A破坏进程B的内存
* Transparency 进程不应该访问实际物理内存
* Resource exhaustion 所有进程占用内存远大于物理内存

### 虚拟内存的目标

每个程序都有自己的虚拟地址空间。

![image](https://user-images.githubusercontent.com/7018329/136682474-bf55d5ac-9d44-4220-ae5c-47669931b835.png)

