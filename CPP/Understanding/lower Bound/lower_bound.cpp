#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
using namespace std;
int main()
{
    vector<int> v({5, 9, 5, 5, 5});
    // sort(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    auto it = lower_bound(v.begin(), v.end(), 9);
    cout << it - v.begin();
    return 0;
}