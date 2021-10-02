## 3. Concurrency 并发

### Sequential Consistency

The result of execution is as if all operations were executed in some sequential order, and the operations of each processor occurred in the order specified by the program.
执行的结果就好像所有的操作都是按照某种顺序执行，每个处理器的操作都是按照程序指定的顺序执行。

使用顺序一致性，会给硬件带来哪些问题：
* Complicates write buffers 使写缓冲区复杂化
* Can’t re-order overlapping write operations 无法重新排序重叠的写入操作
* Complicates non-blocking reads 使非阻塞读取复杂化
* Makes cache coherence more expensive 使缓存一致性更加昂贵

### x86 consistency

x86 supports multiple consistency/caching models. x86支持多种一致性/缓存模型
* Memory Type Range Registers (MTRR) specify consistency for ranges of physical memory (e.g., frame buffer) 内存类型范围寄存器指定物理内存范围的一致性
* Page Attribute Table (PAT) allows control for each 4K page 内存属性表允许控制每个4K页面

Choices include:
- WB: Write-back cachiThe critical section problemng (the default)
- WT: Write-through caching (all writes go to memory)
- UC: Uncacheable (for device memory)
- WC: Write-combining – weak consistency & no caching
(used for frame buffers, when sending a lot of data to GPU)

### critical section problem

关键区域问题：需要相互排斥进入的一个区间，比方需要改动一些关键的共享数据，这个时候不能让两个进程同一时候改动，否则就会出现不可预知的结果了。

Peterson’s solution 是一种基于软件的解决关键区域问题的算法。这种算法可行，需要满足三个条件：
* Mutual Exclusion 互斥
* Progress 在非remaider section的进程能在一定时间内进入critical section
* Bounded waiting 保证一个进程的等待时间不会过长

Peterson expensive, only works for 2 processes.

### mutex and condition variable

注意使用方法


