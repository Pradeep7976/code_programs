#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
using namespace std;
bool isBalanced(string s, int k)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '<')
        {
            count++;
        }
        else
        {
            if (count == 0)
            {
                if (k == 0)
                {
                    return false;
                }
                k--;
                continue;
            }
            count--;
        }
    }
    return (count <= k);
}
vector<int> balancedOrNot(vector<string> expr, vector<int> maxRep)
{
    vector<int> res;
    for (int i = 0; i < expr.size(); i++)
    {
        res.push_back(isBalanced(expr[i], maxRep[i]));
    }
    return res;
}
int main()
{

    return 0;
}