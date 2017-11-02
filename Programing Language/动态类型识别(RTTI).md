## 动态类型识别 

RTTI (Run-Time Type Identification)

动态类型指的是基类指针所指向的对象的实际类型。

**使用虚函数进行动态类型识别的缺陷：**

* 必须从基类开始提供类型虚函数
* 所有的派生类都必须重写类型虚函数
* 每个派生类的类型 ID 必须唯一

### dynamic_cast

dynamic_cast 主要用于基类和派生类之间的转换。

利用 dynamic_cast 进行动态类型识别，必须基类至少有一个虚函数，一般是基类的析构函数为虚函数。

使用 dynamic_cast 的优势

* 不用显示的声明和定义类型虚函数
* 不用为类族中的每个类分配类型 ID

使用 dynamic_cast 的缺陷：只能用于具有虚函数的类族(基类没有虚函数编译失败)。

### typeid

C++ 提供 typeid 关键字用于动态获取类型信息。

* typeid 关键字返回对应参数的类型信息
* typeid 返回一个 type_info 类对象，使用 type_info 类需要包含#include <typeinfo>

```c++
#include <iostream>
#include <stdlib.h>
#include <string>
#include <typeinfo>
using namespace std;


/**
 * 定义移动类：Movable
 * 纯虚函数：move
 */
class Movable
{
public:
    virtual void move() = 0;
};

/**
 * 定义公交车类：Bus
 * 公有继承移动类
 * 特有方法carry
 */
class Bus : public Movable
{
public:
    virtual void move()
    {
        cout << "Bus -- move" << endl;
    }
    
    void carry()
    {
        cout << "Bus -- carry" << endl;
    }
};

/**
 * 定义坦克类：Tank
 * 公有继承移动类
 * 特有方法fire
 */
class Tank : public Movable
{
public:
    virtual void move()
    {
        cout << "Tank -- move" << endl;
    }

    void fire()
    {
        cout << "Tank -- fire" << endl;
    }
};

/**
 * 定义函数doSomething含参数
 * 使用dynamic_cast转换类型
 */
void doSomething(Movable *obj)
{
    obj->move();

    if(typeid(*obj) == typeid(Bus))
    {
        Bus *bus = dynamic_cast<Bus *>(obj);
        bus->carry();
    }

    if(typeid(obj) == typeid(Tank))
    {
        Tank *tank = dynamic_cast<Tank *>(obj);
        tank->fire();
    }
}

int main(void)
{
    Bus b;
    Tank t;
    doSomething(&b);
    doSomething(&t);
    return 0;
}
```












