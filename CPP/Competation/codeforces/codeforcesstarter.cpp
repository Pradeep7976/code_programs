#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            // cout << v[i] << " " << i + 1 << endl;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (v[j] == i + 1)
                {
                    ans = true;
                    break;
                }
            }
            if (ans)
                break;
        }
        // cout << endl;
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}