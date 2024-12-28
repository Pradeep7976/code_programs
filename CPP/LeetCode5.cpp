#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> memo;

int minCoins(int n, int x, vector<int> &coins)
{
    if (n == 0)
    {
        return 0;
    }

    if (memo[n] != -1)
    {
        return memo[n];
    }

    int ans = coins[n - 1] + minCoins(n - 1, x, coins);
    for (int i = 2; i <= min(3, n - 1); ++i)
    {
        ans = min(ans, x + minCoins(n - i, x, coins));
    }

    memo[n] = ans;
    return ans;
}

int doShopping(int n, int x, vector<int> &coins)
{
    memo.resize(n + 1, -1);
    return coins[n - 1] + minCoins(n - 1, x, coins);
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    }

    int result = doShopping(n, x, coins);
    cout << result << endl;

    return 0;
}
