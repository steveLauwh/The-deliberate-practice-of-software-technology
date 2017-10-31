#include <iostream>
using namespace std;

class Grandam
{
public:
     void introduce_self()
    {
        cout << "I am grandam." << endl;
    }
};

class Mother :virtual public Grandam
{
public:
    void introduce_self()
    {
        cout << "I am mother." << endl;
    }
};

class Aunt :virtual public Grandam
{
public:
    void introduce_self()
    {
        cout << "I am aunt." << endl;
    }
};

class Daughter :public Mother,public Aunt
{
public:
    void introduce_self()
    {
        cout << "I am daughter." << endl;
    }
};

int main()
{
    Grandam* ptr;
    Daughter d;

    ptr = &d;

    ptr->introduce_self();

    cout << sizeof(Grandam) << endl;  // 1

    cout << sizeof(Mother) << endl;   // 4

    cout << sizeof(Aunt) << endl;     // 4

    cout << sizeof(Daughter) << endl; // 8

    return 0;
}
