#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
using namespace std;
int counti = 0;

int getMinDiff(vector<int> arr, int n, int k)
{
    // code here
    sort(arr.begin(), arr.end());
    int pos = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] >= 0)
        {
            pos = arr[i];
            break;
        }
    }
    int end = arr[n - 1];
    if (pos != -1)
    {
        if ((arr[n - 1] - k) > 0)
        {
            int ans = abs((arr[n - 1] - k) - (pos + k));
            return ans;
        }
        else
        {
            return (arr[n - 1] - pos);
        }
    }
    else
    {
        return arr[n - 1] - arr[n - 2];
    }
}

void display(int n, vector<vector<int>> v)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
{
    vector<int> ans(2);
    if (tomatoSlices > cheeseSlices)
    {
        return ans;
    }
    if (tomatoSlices % 2 != 0)
    {
        return ans;
    }
    int s = tomatoSlices / 2;
    cout << s;
    ans[0] = s - cheeseSlices;
    ans[1] = s - ans[0];
    return ans;
}

int main()
{
    int n = 15;
    // vector<vector<int>> v{{2, 1}, {4, 4}};

    // vector<int> v = {1, 2, 3, 1, 2, 3, 3, 3};
    vector<int> ans;
    ans = numOfBurgers(16, 7);
    cout << ans[0] << ans[1];
    return 0;
}