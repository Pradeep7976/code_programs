#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
using namespace std;

class A
{
private:
    int regNo;
    char name[10];

public:
    void acceptA()
    {
        cout << "Enter the register no and name" << endl;
        cin >> regNo >> name;
    }
    void displayA()
    {
        cout << "reg No =" << regNo << " Name =" << name << endl;
    }
};

class B : public A
{
private:
    int sem;
    char course[10];

public:
    void acceptB()
    {
        cout << "Enter the Sem and course" << endl;
        cin >> sem >> course;
    }
    void displayB()
    {
        cout << "sem =" << sem << " course =" << course << endl;
    }
};

class c : public B
{
private:
    int m1, m2, m3, total;

public:
    void acceptC()
    {
        cout << "Enter three subject marks" << endl;
        cin >> m1 >> m2 >> m3;
    }

    void displayC()
    {
        cout << "the marks are m1 m2 m3" << m1 << " " << m2 << " " << m3 << " " << endl;
        total = m1 + m2 + m3;
        cout << "total =" << total << endl;
    }
};

int main()
{
    c obj;
    obj.acceptA();
    obj.acceptB();
    obj.acceptC();
    obj.displayA();
    obj.displayB();
    obj.displayC();

    return 0;
}