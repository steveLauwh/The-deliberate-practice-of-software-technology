## 2. Processes

**含义：**
* A process is an instance of a program running. 进程是程序运行的一个实例
* Modern OSes run multiple processes simultaneously 现代操作系统同时运行多个进程


**Why processes?**
* Simplicity of programming 编程简单
* Speed: Higher throughput, lower latency 更高吞吐量，低延迟


**Speed**
* 多进程可以提高CPU利用率
* 多进程可以减少延迟


**A process’s view of the world**

![image](https://user-images.githubusercontent.com/7018329/134156581-f8428f39-4ce8-418a-9e3b-3faacbed2e51.png)


**Inter-Process Communication**

![image](https://user-images.githubusercontent.com/7018329/134158263-0b184c26-ec77-4fc4-b7f7-fc476db15c4c.png)

进程如何实时交互：
* 通过内核传递消息
* 通过共享一个物理内存区域
* 通过异步信号或告警


**(UNIX-centric) User view of processes**
* 创建进程：fork、waitpid
* 删除进程：exit、kill
* 运行进程：execve、execvp、execlp
* 管道：pipe


**Kernel view of processes**

![image](https://user-images.githubusercontent.com/7018329/134161985-8dffdf92-23e2-498e-8066-f80acd7990aa.png)

* Keep a data structure for each process
* Tracks state of the process
* Includes information necessary to run
* Various other data about the process


**Process states**

![image](https://user-images.githubusercontent.com/7018329/134162942-ab607836-5cdb-41d8-b555-dacbd8b39bf6.png)

* Process can be in one of several states
* Which process should kernel run?

**Scheduling**
* Scan process table for first runnable?
* FIFO?
* Priority?

**Preemption**
* 当内核获得控制权时可以抢占进程
* 运行进程可以向量控制到内核
* 周期性定时器中断
* 设备中断
* 上下文切换

**Context switch**

![image](https://user-images.githubusercontent.com/7018329/134166405-fcbdaabd-0b2a-4f49-9722-b3199e2b6d39.png)

**Threads**

![image](https://user-images.githubusercontent.com/7018329/134753552-72763630-1e25-4ce1-8ed1-79180a13fad6.png)
* A thread is a schedulable execution context
* Simple programs use one thread per process
* Multiple threads running in same process’s address space

**Thread package API**
* tid thread_create (void (*fn) (void *), void *); 创建一个线程
* void thread_exit ();  销毁当前线程
* void thread_join (tid thread); 等待线程退出

**Kernel threads**

![image](https://user-images.githubusercontent.com/7018329/134754399-059df9fa-1bd3-4bc4-bcf9-2bbe2434faf6.png)
* Every thread operation must go through kernel
* One-size fits all thread implementation
* General heavy-weight memory requirements

**User threads**

![image](https://user-images.githubusercontent.com/7018329/134754501-0a31fd6d-944d-4fee-b954-95bb59e72c74.png)
* Implement as user-level library (a.k.a. green threads)
* One kernel thread per process
* Allocate a new stack for each thread_create
* Keep a queue of runnable threads
* Replace networking system calls
* Schedule periodic timer signal
* Multi-threaded web server example


