#include <iostream>
#define MULTI(x, y) (x * y)
using namespace std;
void macros(int a, int b)
{
    cout << MULTI(a, b);
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t!=0)
    {
        int a, b;
        cin >> a >> b;
        macros(a, b);
        t--;
    }
    return 0;
}