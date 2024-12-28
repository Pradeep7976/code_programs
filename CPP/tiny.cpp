#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
using namespace std;
int f(int ind, int T, vector<int> &num)
{
    if (ind == 0)
    {
        if (T % num[0] == 0)
            return T / num[0];
        else if ((num[0] - T) % num[0] == 0)
            return num[0] - T / num[0];
        else
            return 1e9;
    }
    int nottake = f(ind - 1, T, num);
    int take = INT_MAX;
    if (num[ind] <= T)
    {
        take = 1 + f(ind, T - num[ind], num);
    }
    return min(take, nottake);
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    int ans = f(num.size() - 1, x, num);
    if (ans >= 1e9)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int main()
{
    if (0)
    {
        cout << "yo bro";
    }
    return 0;
}
