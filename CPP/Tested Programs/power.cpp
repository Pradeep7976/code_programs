#include <iostream>
using namespace std;
int main()
{
    int n, a, b = 1;
    cout << "Enter the number to be raised to power" << endl;
    cin >> a;
    cout << "Enter the exponential" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        b = b * a;
    }
    cout << b;
    return 0;
}