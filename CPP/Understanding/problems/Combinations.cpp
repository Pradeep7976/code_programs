#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
using namespace std;
class Solution
{
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (ind == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if (arr[ind] <= target)
        {
            ds.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        findCombination(ind + 1, target, arr, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> candidates;
    rep(i, 0, n)
    {
        cin >> candidates[i];
    }

    Solution yoyo;
    vector<vector<int>> sol = yoyo.combinationSum(candidates, target);
    for (auto X : sol)
    {
        cout << X << " ";
    }
    return 0;
}