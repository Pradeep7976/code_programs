#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s, t;
    cin >> n;
    cin >> s;
    char prev = s[0];
    int count = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == prev)
            count++;
        else if (s[i] != prev)
        {
            if (count & 1)
                t += prev;
            else
                t.append(2, prev);
            prev = s[i];
            count = 1;
        }
    }
    if (count != 1)
        if (count & 1)
            t += prev;
        else
            t.append(2, prev);
    else
        t += prev;
    cout << t << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        string s, t;
        cin >> n;
        cin >> s;
        string tt = t;
        char last = s[0];
        int sc = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == last)
                sc++;
            else if (s[i] != last)
            {
                if (sc & 1)
                    t += last;
                else
                    t.append(2, last);
                last = s[i];
                sc = 1;
            }
        }
        if (sc != 1)
            if (sc & 1)
                t += last;
            else
                t.append(2, last);
        else
            t += last;
        cout << t << endl;
    }
    return 0;
}