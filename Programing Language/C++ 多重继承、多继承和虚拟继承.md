## C++ 多重继承、多继承和虚拟继承

### 多重继承

A 是基类，B 继承 A，C 又继承 B，这样的关系就是多重继承。

```c++
class A
{
};

class B : public A
{
};

class C : public B
{

};
```

### 多继承

A 是基类，B 是基类，C 继承 A 和 B，这样的关系是多继承。

如果 A 和 B 包含同名的成员变量或成员函数，在 C 中实例化对象，对象调用 A 和 B 的成员变量或成员函数，需要加上作用域。

```c++
class A
{
public:
    int a;
};

class B
{
public:
    int a;
};

class C : public A, public B
{
    C c;
    cout << c.A::a << c.B::a << endl;
};
```

### 虚拟继承

类 A 是基类，类 B 和类 C 继承了类 A，而类 D 既继承类 B 又继承类 C（这种菱形继承关系）

实例化 D 对象调用类 A 的成员，会产生二义性，并且每个 D 的实例化对象中都有两份完全相同的 A 的数据，会产生数据冗余。

```c++
class A
{
public:
    int i_A;
};

class B : public A
{
};

class C : public A
{
};

class D : public B, public C
{
};
```
 
虚拟继承 就是为了解决菱形继承的二义性问题，在继承间接共同基类时只保留一份成员。

```c++
class A   // A 为虚基类
{
public:
    int i_A;
};

class B : virtual public A
{
};
 
class C : virtual public A
{
};

class D : public B, public C
{
};
```

虚基类并不是在声明基类时声明的，而是在声明派生类时，指定继承方式时声明的。

声明虚基类的一般形式为：class 派生类名: virtual 继承方式 基类名 

### 总结

* 多继承下，如果两个基类有同名的数据成员或成员函数，在派生类下直接调用数据成员或成员函数，也会产生二义性，调用需要加上作用域
* 使用虚拟继承来解决菱形继承的二义性和数据冗余

## 参考

* [多重继承、多继承、虚继承](http://blog.csdn.net/kkdd2013/article/details/51999896)
* [C++ 中的继承](http://blog.csdn.net/chan0311/article/details/69791225)
* [菱形继承的二义性和数据冗余问题](http://blog.csdn.net/chan0311/article/details/75579099)
* [多重继承和虚继承的内存布局](http://blog.csdn.net/littlehedgehog/article/details/5442430)

