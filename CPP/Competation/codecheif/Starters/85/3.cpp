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
    // t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        // n = 4;
        vector<int> v(n);
        // vector<int> v({1, 0, 2, 3});
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int ans = 0;
        int run = 0;
        for (int i = 1; i <= n; i++)
        {
            run += v[i-1];
            double a = (run / double(i));
            if (a == 1.0)
            {
                ans++;
            }
            // cout << v[i] << " ";
        }
        cout << ans << endl;
    }
}