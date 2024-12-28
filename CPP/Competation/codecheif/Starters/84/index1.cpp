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
        int n;
        cin >> n;
        string s;
        cin >> s;
        string xx = "1", xy = "0";
        for (int i = 1; i < n; i++)
        {
            xx += (xx[i - 1] == s[i - 1]) ? "0" : "1";
            xy += (x2[i - 1] == s[i - 1]) ? "0" : "1";
        }
        int o = 0, z = 0;
        for (int i = 0; i < n; i++)
        {
            if (xx[i] == '1')
                o++;
            if (xy[i] == '1')
                z++;
        }
        cout << max(z, o) << endl;
    }
}