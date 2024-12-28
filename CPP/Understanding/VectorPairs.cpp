#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long int
using namespace std;
int main()
{
    vector<pair<int, int>> v(8);
    for (int i = 0; i < 8; i++)
    {
        v[i].first = i + 1;
    }
    vector<pair<int, int>> v2;
    for (int i = 0; i < 15; i++)
    {
        v2.push_back(make_pair(i + 1, 0));
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " ";
    }
    cout << endl;
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i].first << " ";
    }
    return 0;
}