#include <bits/stdc++.h>
using namespace std;
void display(vector<int> v)
{
    int sum;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int sum(vector<int> v)
{
    int an = 0;
    for (int i = 0; i < v.size(); i++)
    {
        an += v[i];
    }
    return an;
}
int waysToSplit(vector<int> &nums)
{
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    int ans = 0;
    v1.push_back(nums[0]);
    v2.push_back(nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
        v3.push_back(nums[i]);
    }
    vector<int>::iterator it1, it2, it3;
    it1 = v1.begin();
    it2 = v2.begin();
    it3 = v3.begin();
    while (v3.size() != 1)
    {
        if (sum(v2) > sum(v1) && sum(v3) > sum(v2))
            ans++;
        int a = sum(v1);
        int b = sum(v2);
        int c = sum(v3);
        if (sum(v1) < sum(v2))
        {
            v1.push_back(*it2);
            v2.pop_back();
            v2.push_back(*it3);
            v3.erase(it3);
        }
        // if (accumulate(it2, v2.end(), 0) > accumulate(it1, v1.end(), 0) && accumulate(it3, v3.end(), 0) > accumulate(it2, v2.end(), 0))
        //     ans++;
        // int a = accumulate(it1, v1.end(), 0);
        // int b = accumulate(it2, v2.end(), 0);
        // int c = accumulate(it3, v3.end(), 0);
        // if (accumulate(it1, v1.end(), 0) < accumulate(it2, v2.end(), 0))
        // {
        //     v1.push_back(*it2);
        //     v2.pop_back();
        //     v2.push_back(*it3);
        //     v3.erase(it3);
        // }
        else
        {
            v2.push_back(*it3);
            v3.erase(it3);
        }
        display(v1);
        display(v2);
        display(v3);
        cout << endl
             << endl;
    }
    return ans;
}

int minDeletionSize(vector<string> &strs)
{
    int count = 0;
    for (int i = 0; i < strs[0].size(); i++)
    {
        for (int j = 1; j < strs.size(); j++)
        {
            if (strs[j][i] < strs[j - 1][i])
            {
                count++;
                break;
            }
        }
    }
    return count;
}

int main()
{
    string s = "ab";
    if (s[0] > s[1])
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
