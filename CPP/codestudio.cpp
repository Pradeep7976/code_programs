#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
using namespace std;

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs[0].begin(), jobs[0].end());
    sort(jobs[1].begin(), jobs[1].end());
    int n = jobs[0].size();
    int maxi = jobs[1][0];
    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, jobs[1][i]);
    }

    int slot[maxi + 1];

    for (int i = 0; i <= maxi; i++)
        slot[i] = -1;

    int countJobs = 0, jobProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[1][i]; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                countJobs++;
                jobProfit += jobs[0][i];
                break;
            }
        }
    }
    return countJobs;
}
int main()
{
    int a, b;
    vector<int> v({2, 4, 6, 7, 9, 9});
    vector<int> v2({1, 3, 0, 5, 8, 5});
    // maximumMeetings(v2, v);
    return 0;
}