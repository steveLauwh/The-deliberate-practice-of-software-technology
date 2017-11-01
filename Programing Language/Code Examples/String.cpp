#include <iostream>
#include <cstring>

using namespace std;

// 实现 String 类
class String
{
public:
    // 普通构造函数
    String(const char *str = NULL) {
	if (str == NULL) {
	    m_data = new char[1];
	    m_data = '\0';
	} else {
	    int length = strlen(str);

	    m_data = new char[length + 1];

	    strcpy(m_data, str);
	}			
    }

    // 拷贝构造函数,深复制
    String(const String &other) {
	if (!other.m_data) {
	    m_data = NULL;
	}

	m_data = new char[strlen(other.m_data) + 1];

	strcpy(m_data, other.m_data);
    }

    // 析构函数
    ~String() {
	if (m_data) {
	    delete[] m_data;
	    m_data = NULL;
	}
    }

    // 重载 + 字符串连接, 不能返回引用
    String operator+(const String &other) const {
	String newString;

	delete[] newString.m_data;

	if (!other.m_data) {
	    newString = *this;	
	} else if (!m_data) {
	    newString = other;
	} else {
	    newString.m_data = new char[strlen(m_data) + strlen(other.m_data) + 1];
	    strcpy(newString.m_data, m_data);
	    strcat(newString.m_data, other.m_data);
	}

	return newString;
    }

    // 重载 = 赋值
    String& operator=(const String &other) {
	if (this != &other) {
	    delete[] m_data;

	    if (!other.m_data) {
		m_data = NULL;
	    } else {
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);
	    }
	}

	return *this;
    }

    // 重载 ==
    bool operator==(const String &other) const {
	if (strlen(m_data) != strlen(other.m_data)) {
	    return false;
	} else {
            return strcmp(m_data, other.m_data) ? false : true;
	}
    }

    // 重载 +=
    String& operator+=(const String &other) {
        char *newData = new char[strlen(m_data) + strlen(other.m_data) + 1];

	strcpy(newData, m_data);
	strcat(newData, other.m_data);

	delete[] m_data;

	m_data = newData;

	return *this;
    }

    // 重载 []
    char& operator[](int n) const {
	if (n >= strlen(m_data)) {
	    return m_data[strlen(m_data) - 1];
	}

	return m_data[n];
    }

    // 获取长度
    int getLength() const {
	return strlen(m_data);
    }

    // 输入, 重载输入操作，需要先申请一块内存，用于存放输入字符串
    friend istream& operator>>(istream &is, String &str) {
	char strTemp[100];

	memset(strTemp, 0, sizeof(strTemp));

	is >> strTemp;

	str.m_data = new char[strlen(strTemp) + 1];

	strcpy(str.m_data, strTemp);

	return is;
    }

    // 输出
    friend ostream& operator<<(ostream &os, String &str) {
	os << str.m_data;

	return os;
    }

private:
    char *m_data;
};

// 测试
int main()
{
    String s;

    cin >> s;

    cout << s << " : " << s.getLength() << endl;

	
    String s1(s);
	
    cout << s1 << " : " << s1.getLength() << endl;

    const char *str = "Hello";

    String s2(str);

    cout << s2 << " : " << s2.getLength() << endl;


    char str1[] = "world!";

    String s3(str1);

    cout << s3 << " : " << s3.getLength() << endl;

    String s4 = s3;

    if (s4 == s3) {
	cout << "s3 == s4" << endl;
    } else {
	cout << "s3 != s4" << endl;
    }

    String s5 = s3 + s4;

    cout << s5 << " : " << s5.getLength() << endl;
	
    s3 += s4;

    if (s5 == s3) {
	cout << "s5 == s3" << endl;
    } else {
	cout << "s5 != s3" << endl;
    }

    cout << s5[5] << endl;
	
    return 0;
}
