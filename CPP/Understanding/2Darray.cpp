#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
using namespace std;
int main()
{
    int m;
    cin >> m;
    int arr[m][m];
    rep(i, 0, m)
    {
        rep(j, 0, m)
        {
            cin >> arr[i][j];
        }
    }
    int right = 0;
    int left = m - 1;
    int rightsum = 0;
    rep(i, 0, m)
    {
        rightsum += arr[right][left];
        cout << rightsum << "   " << arr[right][left] << endl;
        left--;
        right++;
    }
    cout << endl
         << endl
         << endl
         << endl
         << endl;
    int lefti = 0, righti = 0;
    int leftsum = 0;
    rep(i, 0, m)
    {
        leftsum += arr[lefti][righti];
        lefti++;
        righti++;
    }
    // cout << rightsum << "  " << leftsum;
    cout << abs(rightsum - leftsum);
    return 0;
}