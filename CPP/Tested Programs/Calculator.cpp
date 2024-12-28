
#include <iostream>

using namespace std;

class SimpleCalculator
{
public:
    void add(int a, float b)
    {
        cout << a + b;
    }
    void multi(int a, float b)
    {
        cout << a * b;
    }
    void minus(int a, float b)
    {
        cout << a - b;
    }
    void div(int a, float b)
    {
        cout << a / b;
    }
};

int main()
{
    char c;
    int a;
    float b;
    cout << "Your Calculator Is Ready" << endl;
    cin >> a;
    cin >> c;
    cin >> b;

    SimpleCalculator *calc = new SimpleCalculator;
    if (c = '+')
    {
        calc->add(a, b);
    }
    if (c = '*')
    {
        calc->multi(a, b);
    }
    if (c = '-')
    {
        calc->minus(a, b);
    }
    if (c = '/')
    {
        calc->div(a, b);
    }

    return 0;
}