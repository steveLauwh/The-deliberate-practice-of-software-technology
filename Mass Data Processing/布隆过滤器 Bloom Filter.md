# 布隆过滤器 Bloom Filter

海量数据的排重算法，适用于对空间资源要求很高，同时能容忍 “零错误” 的应用场合。

### 什么是布隆过滤器算法

Bloom Filter 是一种空间效率很高的随机数据结构，它利用位数组很简洁地表示一个集合，并能判断一个元素是否属于这个集合。

而在能容忍低错误率的应用场合下，Bloom Filter 通过极少的错误换取了存储空间的极大节省。

### 核心原理

Bloom Filter 算法的核心思想就是利用多个不同的 Hash 函数来解决“冲突”。

Hash 存在一个冲突（碰撞）的问题，用同一个 Hash 得到的两个 URL 的值有可能相同。为了减少冲突，我们可以多引入几个 Hash，
如果通过其中的一个 Hash 值我们得出某元素不在集合中，那么该元素肯定不在集合中。只有在所有的 Hash 函数告诉我们该元素在集合中时，
才能确定该元素存在于集合中。这便是 Bloom Filter 的基本思想。

核心原理：

**1. 位数组**

初始状态时，Bloom Filter 是一个包含 m 位的位数组，每一位都置为 0。

**2. 使用 k 个相互独立的哈希函数**

为了表达 `S = {x1, x2,…,xn}` 这样一个 n 个元素的集合，Bloom Filter 使用 k 个相互独立的哈希函数（Hash Function），
它们分别将集合中的每个元素映射到 {1,…,m} 的范围中。当我们往 Bloom Filter 中增加任意一个元素 x 时候，我们使用 k 个哈希函数得到 k 个哈希值，
然后将数组中对应的比特位设置为 1。即第 i 个哈希函数映射的位置 `hash(x)` 就会被置为 1（1≤i≤k）。

**3. 判断元素是否存在集合中**

判断某个元素 x 是否在集合中，当 x 使用 k 个哈希函数 hash，得到 k 个哈希值 hash(x)，其位置都是为 1，那么说明元素 x 是存在集合中。

### 特点(有误判，但不会漏掉存在元素)

在判断一个元素是否属于某个集合时，有可能会把不属于这个集合的元素误认为属于这个集合（False Positive），
但不会把属于这个集合的元素误认为不属于这个集合（False Negative）；因此，Bloom Filter 不适合那些“零错误”的应用场合。

### 优缺点

优点：空间效率和查询时间都远远超过一般的算法。

缺点：有一定的误识别率和删除困难。

### 改进

一个简单的改进就是 counting Bloom filter，用一个 counter 数组代替位数组，就可以支持删除了。

一个 Bloom Filter 有以下参数：

* m	- 位数组的宽度（bit数）
* n	- 加入其中的 key 的数量
* k	- 使用的 hash 函数的个数
* f	- False Positive 的比率

当 `k = ln(2)* m/n` 时出错的概率是最小的。

`m >= nlg(1/E)1.44`(lg表示以2为底的对数)。 

### 应用

由于 Bloom Filter 所用的空间非常小，所有 Bloom Filter 可以常驻内存。那么对于大部分不存在的元素，
我们只需要访问内存中的 Bloom Filter 就可以判断出来了，
只有一小部分，我们需要访问在硬盘上的 key-value 数据库。从而大大地提高了效率。

## 参考

* [Bloom Filter 概念和原理](http://blog.csdn.net/jiaomeng/article/details/1495500)
* [海量数据处理算法—Bloom Filter](http://blog.csdn.net/hguisu/article/details/7866173)
* [布隆过滤器(Bloom Filter)详解](http://www.cnblogs.com/allensun/archive/2011/02/16/1956532.html)
