#include <iostream>

using namespace std;

class Test
{
public:
    Test(int x, int y) : i_x(x)
    {
        i_y = y;
    }

    int getX() const
    {
        return i_x;
    }

    int getY()
    {
        return i_y;
    }

    void setY(int y)
    {
        i_y = y;
    }

    void printInfo() const
    {
        cout << getX() << endl;
    }

    ~Test() {}

private:
    const int i_x;
    int i_y;
};

int main() {
    Test t(1, 2);

    cout << "i_x = " << t.getX() << "\t" << "i_y = " << t.getY() << endl;

    t.setY(5);

    cout << "i_y = " << t.getY() << endl;

    t.printInfo();

    return 0;
}
