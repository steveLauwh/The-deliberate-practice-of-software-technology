## C++ 常对象成员和常成员函数

[实例](https://github.com/steveLauwh/The-deliberate-practice-of-software-technology/blob/master/Programing%20Language/Code%20Examples/ConstObjectMember.cpp)

**1. 常对象成员如何初始化**

* 类的 const 成员变量必须在构造函数的参数初始化列表中进行初始化
* 构造函数内部，不能对 const 成员变量赋值，编译器直接报错。

**2. 常成员函数**

```
<类型标志符> 函数名(参数表) const
{
}
```

```c++
void Coordinate::changeX() const
{
    m_iX = 10;
}

编译器理解成下面这样，this 指针是常指针

void changeX(const Coordinate *this)
{
    this->m_iX = 10;
}
```

* 常成员函数不能改变数据成员的值
* const 关键字可以用于对重载函数的区分
* 常成员函数不能调用该类中没有用 const 修饰的成员函数，只能调用常成员函数
* 常成员函数的本质是内部使用常 this 指针

