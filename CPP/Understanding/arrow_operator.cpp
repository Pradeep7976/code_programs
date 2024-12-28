#include <iostream>
using namespace std;
class oper
{
private:
    int f = 99;

public:
    void show(int b)
    {
        cout << b + f;
    }
};
int main()
{
    int f = 1;
    // oper a; //one way of creating an object
    // a.show(f);
    oper *lol = new oper; //DYNAMIC OBJECT || another way to declare the objects
    lol->show(f);
    return 0;
}