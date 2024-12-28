//we convert number into string when we want to itrate through the digits

#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
using namespace std;
int main()
{
    int t = 78878;
    string s;
    s = to_string(t);
    rep(i, 0, s.length())
            cout<< s[i] << " ";

    //output         
    return 0;
}