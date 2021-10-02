## 3. Concurrency

### Sequential Consistency

The result of execution is as if all operations were executed in some sequential order, and the operations of each processor occurred in the order specified by the program.
执行的结果就好像所有的操作都是按照某种顺序执行，每个处理器的操作都是按照程序指定的顺序执行。

使用顺序一致性，会给硬件带来哪些问题：
* Complicates write buffers 使写缓冲区复杂化
* Can’t re-order overlapping write operations 无法重新排序重叠的写入操作
* Complicates non-blocking reads 使非阻塞读取复杂化
* Makes cache coherence more expensive 使缓存一致性更加昂贵

