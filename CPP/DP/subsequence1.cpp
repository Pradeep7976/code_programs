#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
using namespace std;

void vectordisplay(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
int subarraySumUtil(vector<int> &nums, int ind, int k)
{
    if (k == 0)
        return 1;
    if (ind < 0)
        return 0;
    int pick = subarraySumUtil(nums, ind - 1, k - nums[ind]);
    int notpick = subarraySumUtil(nums, ind - 1, k);
    return pick + notpick;
}
int subarraySum(vector<int> &nums, int k)
{
    return subarraySumUtil(nums, nums.size() - 1, k);
}
int findWaysUtil(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
{

    if (sum < 0)
        return 0;
    if (ind == 0)
    {
        if (sum == 0 && arr[0] == 0)
            return 2;
        if (arr[0] == sum || sum == 0)
            return 1;
        return 0;
    }

    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    int notTaken = findWaysUtil(ind - 1, sum, arr, dp);

    int taken = 0;
    if (arr[ind] <= sum)
        taken = findWaysUtil(ind - 1, sum - arr[ind], arr, dp);

    return dp[ind][sum] = notTaken + taken;
}
int targetSumutil(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
{

    if (sum < 0)
        return 0;
    if (ind == 0)
    {
        if (arr[0] + sum == 0 || arr[0] - sum == 0)
            return 1;
        return 0;
    }

    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    int notTaken = targetSumutil(ind - 1, sum + arr[ind], arr, dp);

    int taken = 0;
    if (arr[ind] <= sum)
        taken = targetSumutil(ind - 1, sum - arr[ind], arr, dp);

    return dp[ind][sum] = notTaken + taken;
}

int targetSum(int n, int target, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return targetSumutil(n - 1, target, arr, dp);
}

int f(int ind, int T, vector<int> &num)
{
    if (ind == 0)
    {
        if (T % num[0] == 0)
            return T / nums[0];
        else if ((num[0] - T) % nums[0] == 0)
            return nums[0] - T / nums[0];
        else
            return 1e9;
    }
    int nottake = f(ind - 1, T, num);
    int take = INT_MAT;
    if (num[ind] <= T)
    {
        take = 1 + f(ind, T - num[ind], num);
    }
    return min(take, nottake);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    return f(num.size() - 1, x, num);
}
int main()
{
    int n;
    vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    // cin >> n;
    vector<int> arr({1, 2, 3});
    cout << minimumElements(arr, 7);
}