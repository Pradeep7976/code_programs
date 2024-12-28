#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
using namespace std;
int stringi(string s)
{
    int n = s.length();
    int arr[n + 1];
    arr[n] = 1;
    arr[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        cout << "Loop" << endl;
        cout << s[i] << " " << s[i + 1] << endl;
        if (s[i] != s[i + 1])
        {
            arr[i] = (arr[i + 1] + arr[i + 2]) % 998244353;
            cout << arr[i + 1] << " " << arr[i + 2] << endl;
        }
        else
        {
            arr[i] = arr[i + 1];
            cout << arr[i + 1] << endl;
        }
    }
    return arr[0] % 998244353;
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        string str = "abb";
        // cin >> str;
        cout << stringi(str) << endl;
    }
    return 0;
}