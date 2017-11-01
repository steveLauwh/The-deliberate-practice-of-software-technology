## 实现 String 类

```c++
class String
{
public:
    String(const char *str = NULL);	// 构造函数
    String(const String &str);		// 拷贝构造函数
    ~String();						// 析构函数

    String operator+(const String &str) const;	// 重载+
    String& operator=(const String &str);		// 重载=
    String& operator+=(const String &str);		// 重载+=
    bool operator==(const String &str) const;	// 重载==
    char& operator[](int n) const;				// 重载[]

    int getLength() const;		//获取长度

    friend istream& operator>>(istream &is, String &str); // 输入
    friend ostream& operator<<(ostream &os, String &str); // 输出

private:
    char *data;		//字符串
};
```

String 类其实是对一个字符串指针的一系列操作。运用 C 库：strcpy、strcmp、strlen、strcat、memset 等。

注意点：

重载 operator+ 运算符，不能返回引用，因为返回的对象是一个临时的对象,运算完后就会自动释放。

## [String 类-Code](https://github.com/steveLauwh/The-deliberate-practice-of-software-technology/blob/master/Programing%20Language/Code%20Examples/String.cpp)
