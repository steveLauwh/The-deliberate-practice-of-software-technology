## 4. CPU Scheduling

![image](https://user-images.githubusercontent.com/7018329/135996916-e363d301-6581-450f-899b-5abad0aa0307.png)

![image](https://user-images.githubusercontent.com/7018329/135997214-58022025-982b-4231-89f5-34c6ff3dd986.png)

### When do we schedule CPU?

![image](https://user-images.githubusercontent.com/7018329/136181224-8091b9a9-b694-4e5e-b648-151a9c7966c6.png)

### Scheduling criteria 调度标准

* Throughput 吞吐量：每单位时间完成的进程数量（越高越好）
* Turnaround time 周转时间：完成每个流程的时间（越低越好）
* Response time 响应时间：从请求到第一次响应的时间

以上标准会受次要标准影响，如：
* CPU utilization：CPU执行工作的时间比例
* Waiting time：每个进程在就绪队列中等待的时间

### 调度算法

* FCFS Scheduling：First-come first-served (FCFS) 先到先得
* SJF Scheduling：Shortest-job first (SJF) 最短作业优先
* Round robin (RR) scheduling：循环调度

### Priority scheduling

将数字优先级与每个进程相关联

### Scheduling with virtual time


