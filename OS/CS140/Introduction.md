## 1. Introduction

### Class web page: http://cs140.scs.stanford.edu/

### Course topics：
* Threads & Processes 线程和进程
* Concurrency & Synchronization 并发和同步
* Scheduling 调度
* Virtual Memory 虚拟内存
* I/O  输入和输出
* Disks, File systems  磁盘，文件系统
* Protection & Security 保护和安全
* Virtual machines 虚拟机

### Course goals
* 介绍操作系统概念
* 涵盖重要的系统概念：Caching, concurrency, memory management, I/O, protection
* 如何处理更大的软件系统

### What is an operating system?
* Layer between applications and hardware
* Makes hardware useful to the programmer
* Provides abstractions for applications
* Provides protection

![image](https://user-images.githubusercontent.com/7018329/132988826-e2ade9b3-49f5-4a74-a0ea-a494400d8569.png)

### Why study operating systems?
* 操作系统是一个成熟的领域
* 操作系统一直存在开放问题:安全和可扩展性
* 高性能服务器
* 资源消耗
* 新“智能”设备需要新的操作系统

### 操作系统的特性
* 多任务（抢占，内存保护）
* 多用户
* Protection 保护机制
* 提供 System calls 机制给用户，访问内核
* Address translation 地址转换，虚实地址
* Context switch 上下文切换
