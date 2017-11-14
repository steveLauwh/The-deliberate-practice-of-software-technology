## listen 的 backlog 参数

```c
#include <sys/socket.h>

// listen 只是用来开启，并设置 accept队列的长度
int listen(int sockfd, int backlog);
```

TCP 三次握手过程中，操作系统内核维护两个队列，SYN 队列(未完成握手队列)和 Accept 队列(已完成握手队列)。

当服务器 bind，listen 某个端口后，这个端口的 SYN 队列和 Accept 队列就建立好。

* 服务器收到客户端 SYN 包，发送 SYN+ACK 包后，在内存创建一个状态为 SYN_RCVD 的连接，放入 未完成队列
* 服务器收到客户端 ACK 包后，该连接的状态由 SYN_RCVD 改为 ESTABLISHED，并移到已完成队列
* 服务器程序调用 accept 后,该连接移除 已完成队列, 由内核交给程序控制

## 总结：

在 Linux 下，backlog 指定的是 complete queue 的大小，而 incomplete queue 的大小可以由系统管理员在 `/proc/sys/net/ipv4/tcp_max_syn_backlog` 下进行统一配置。

```
net.ipv4.tcp_syncookies = 1
表示开启 SYN Cookies。当出现 SYN 等待队列溢出时，启用 cookies 来处理，可防范少量 SYN 攻击，默认为 0，表示关闭。

net.ipv4.tcp_tw_reuse = 1
表示开启重用。允许将 TIME-WAIT sockets 重新用于新的 TCP 连接，默认为 0，表示关闭。

net.ipv4.tcp_tw_recycle = 1
表示开启 TCP 连接中 TIME-WAIT sockets 的快速回收，默认为 0，表示关闭。
```

## 参考

* [TCP listen 的 backlog 参数](http://www.jianshu.com/p/fe2228a77429)
