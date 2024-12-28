// Delete and Append problem in HakerRank

// hackerhappy  11
// hackerrank   10

// ash
//ash

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    int k;
    cin >> s >> t >> k;
    int p = 0;
    while (p < min(s.size(), t.size()) && s[p] == t[p])
        ++p;
    int vmin;
    if (k == (s.size() + t.size()))
        vmin = s.size() + t.size() - 2 * p;
    else
        vmin = s.size() + t.size() + 1;
    if (k < vmin)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}