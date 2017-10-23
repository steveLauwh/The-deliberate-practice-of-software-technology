## C++ STL map

map 是一个关联式容器，key 和 value 可以是任意的类型。对于 key 的类型，唯一的约束是必须支持 < 操作符。

根据 key 值快速查找记录，查找的复杂度基本是 log(N)。

### 当 key 为自定义类型

当 key 为自定义类型，需要重载 < 操作符。

```c++
#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef struct tagTestInfo
{
    int id;
    string name;
    
    bool operator< (const tagTestInfo& t) const {
        if (id < t.id) {
            return true;
        } else if (id == t.id) {
            if (name.compare(t.name) < 0) {
                return true;
            }
        }
        
        return false;
    }
}tst;

int main()
{
    map<tst, int> mp;
    
    tst t;
    
    // map 插入的三种方式
    t.id = 1;
    t.name = "steve";
    mp.insert(pair<tst, int>(t, 11));
    
    t.id = 2;
    t.name = "Lau";
    mp.insert(map<tst, int>::value_type(t, 12));
    
    t.id = 3;
    t.name = "Li";
    mp[t] = 13;
    
    // 使用 pair 来判断插入是否成功
    t.id = 4;
    t.name = "Wang";
    pair<map<tst, int>::iterator, bool> insert_pair;
    insert_pair = mp.insert(pair<tst, int>(t, 14));
    if (insert_pair.second == true) {
        cout << "Insert Success!" << endl;
    } else {
        cout << "Insert Fail!" << endl;
    }
    
    // 遍历
    map<tst, int>::iterator it;
    
    for (it = mp.begin(); it != mp.end(); it++) {
        cout << it->first.id << " " << it->first.name << " " << it->second << "\t";
    }
    
    cout << endl;
    
    return 0;
}
```

### 当 value 为自定义类型

value 为自定义类型，操作跟普通类型是一样的。

```c++
#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef struct tagTestInfo
{
    int id;
    string name;
}tst;

int main()
{
    map<string, tst> mp;
    
    tst t;
    
    // map 插入的三种方式
    t.id = 1;
    t.name = "steve";
    mp.insert(pair<string, tst>("str1:", t));
    
    t.id = 2;
    t.name = "Lau";
    mp.insert(map<string, tst>::value_type("str2:", t));
    
    t.id = 3;
    t.name = "Li";
    mp["str3:"] = t;
    
    // 使用 pair 来判断插入是否成功
    t.id = 4;
    t.name = "Wang";
    pair<map<string, tst>::iterator, bool> insert_pair;
    insert_pair = mp.insert(pair<string, tst>("str4:", t));
    if (insert_pair.second == true) {
        cout << "Insert Success!" << endl;
    } else {
        cout << "Insert Fail!" << endl;
    }
    
    // 遍历
    map<string, tst>::iterator it;
    
    for (it = mp.begin(); it != mp.end(); it++) {
        cout << it->first<< " " << it->second.id << " " << it->second.name << "\t";
    }
    
    cout << endl;
    
    return 0;
}
```

### map 的删除 erase 方法

迭代器遍历删除某键值对时，对应的迭代器就会失效，正确的操作如下：

```c++
#include <iostream>
#include <map>
#include <string>

using namespace std ;

int main() 
{ 
    map<int, string> mp ;
    mp.insert(pair<int, string>(1, "steve"));
    mp.insert(pair<int, string>(2, "Lau"));
    mp.insert(pair<int, string>(3, "Li"));
    mp.insert(pair<int, string>(4, "Wang"));

    map<int, string>::iterator it;
    
#if 0
    // 错误的写法
    for (it = mp.begin(); it != mp.end(); ++it)
    {
        if (it->second == "steve")
        {
            mp.erase(it) ; // map 是关联式容器，调用 erase 后，当前迭代器已经失效
        }
    }
#endif

    // 正确的写法
    for (it = mp.begin(); it != mp.end();)
    {
        if (it->second == "steve")
        {
            mp.erase(it++) ; // erase之后，令当前迭代器指向其后继。
        }
        else
        {
            ++it;
        }
    }

    // 另一个正确的写法，利用 erase 的返回值
    for (it = mp.begin(); it != mp.end();)
    {
        if (it->second == "Lau")
        {
            it = mp.erase(it) ; // erase 的返回值是指向被删除元素的后继元素的迭代器
        }
        else
        {
            ++it;
        }
    }

    map<int, string>::const_iterator citor ;
    for (citor = mp.begin(); citor != mp.end(); ++citor)
    {
        cout << citor->first << ":" << citor->second << endl ;
    }

    return 0; 
}
```

## 参考

* http://www.cplusplus.com/reference/map/map/
