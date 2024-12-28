#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;

    string str;
    cout << "Enter text" << endl;
    getline(cin, str);
    cout << "Enter no of times text to be repeated" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ". " << str << endl;
    }

    return 0;
}