#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
using namespace std;
int ans = 0;
void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int dectobin(string s)
{
    int p = 0;
    int i = 0;
    int m = s.length() - 1;
    while (m >= 0)
    {
        int rem = (s[m] - '0') % 10;
        m--;
        p += pow(2, i) * rem;
        i++;
    }
    return p;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int x = dectobin(s);
        int maxi = INT_MIN;
        int ans = 0;
        for (int i = 1; i <= s.length(); i++)
        {
            int val = x / (pow(2, i));
            int orr = x ^ val;
            if (orr > maxi)
            {
                maxi = orr;
                ans = i;
            }
        }
        cout << ans;
    }
    return 0;
}