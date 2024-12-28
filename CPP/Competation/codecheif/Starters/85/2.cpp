#include <bits/stdc++.h>
using namespace std;
#define rep(a, b, c) for (int a = b; a < c; a++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int st, tik;
        cin >> st >> tik;
        if (tik >= st)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << st - tik << endl;
        }
    }
}