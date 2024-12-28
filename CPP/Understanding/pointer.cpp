#include <iostream>

using namespace std;

void point(int *g, int *h)
{
    int n;
    n = *g;
    *g = *h;
    *h = n;
}
void sum(int &a, int &b)
{
    a = a + 5;
}
int main()
{
    int a, b;
    cin >> a >> b;
    // int *aptr=&a;
    // int *bptr=&b;
    point(&a, &b);
    // cout << a << endl;
    // cout << b;
    sum(a, b);
    cout << a;
    return 0;
}