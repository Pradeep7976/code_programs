#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define vi vector<int>
using namespace std;
int main()
{
    bool yo = true;
    string s;
    s = "malayalam";
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    // rep(i, 0, s.length())
    // {
    //     cout << st.top() << endl;
    //     st.pop();
    // }
    rep(i, 0, s.length())
    {
        if (s[i] != st.top())
        {
            yo = false;
            break;
        }
        st.pop();
    }
    if (yo)
    {
        cout << "yes";
    }
    return 0;
}