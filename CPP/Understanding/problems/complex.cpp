#include <iostream>
using namespace std;
class complex
{
private:
    int real;
    int imag;

public:
    complex(com)
    {
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int c11, c12, c21, c22;
        cin >> c11 >> c12 >> c21 >> c22;

        complex c1, c2, c3;
        c1 = complex(c11, c12);
        c2 = complex(c21, c22);
        c3 = c1 + c2;
        c3.display();
    }
}