#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define vi vector<int>
using namespace std;
int main()
{
    vi a(6);
    a = {1, 2, 1, 3, 2, 1};
    map<int, int> freq;
    rep(i, 0, 6)
    {
        freq[a[i]]++;
    }
    map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    
    return 0;
}