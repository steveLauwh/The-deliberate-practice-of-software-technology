## Singleton 单例模式(C++)

单例模式的适用场景是对于定义的一个类，在整个应用程序执行期间只有唯一的一个实例对象。

```c++
class Singleton
{
public:
    static Singleton *getInstance() {
        if (0 == inst) {
            static Singleton instance;  // 通过在函数内部定义静态变量的方法获得类实例
            inst = &instance;
        }
        
        return inst;
    }

private:
    Singleton() {};
    ~Singleton() {};
    static Singleton *inst;
};
```

## 参考

* [C++ 完美实现 Singleton 模式](http://blog.csdn.net/eggfly178/article/details/42029651)
