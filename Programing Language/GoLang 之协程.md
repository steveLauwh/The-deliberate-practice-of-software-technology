## GoLang 之协程

WebServer几种主流的并发模型：

* 多线程，每个线程一次处理一个请求，在当前请求处理完成之前不会接收其它请求；但在高并发环境下，多线程的开销比较大
* 基于回调的异步 IO，如 Nginx 服务器使用的 epoll 模型，这种模式通过事件驱动的方式使用异步 IO，使服务器持续运转，但人的思维模式是串行的，大量回调函数会把流程分割，对于问题本身的反应不够自然
* 协程，不需要抢占式调度，可以有效提高线程的任务并发性，而避免多线程的缺点；但原生支持协程的语言还很少
 
协程（coroutine）是 Go 语言中的轻量级线程实现，由 Go 运行时（runtime）管理。

goroutine 机制实现了 M : N 的线程模型，goroutine 机制是协程（coroutine）的一种实现，GoLang 内置的调度器，可以让多核 CPU 中每个 CPU 执行一个协程。

## 参考

* [GO 语言、DOCKER 和新技术](https://coolshell.cn/articles/18190.html)
* [Go 语言之并发](https://www.cnblogs.com/cyzsoho/p/4849874.html)
