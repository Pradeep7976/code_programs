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

int main()
{
    vector<int> v = {2, 6, 3, 4, 7, 2, 10, 3, 2, 1};
    cout << getMinDiff(v, 10, 5);
    return 0;
}
