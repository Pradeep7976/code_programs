#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;

        vector<int> diag1(n, 0), diag2(n, 0);

        for (int i = 0; i < n; i++)
        {
            int x, y;
            x = i, y = i;
            if (i % 2 == 1)
            {
                y += 1;
            }
            diag1[i] = x + y;
            diag2[i] = x - y;
        }

        sort(diag1.begin(), diag1.end());
        sort(diag2.begin(), diag2.end());

        int moves1 = 0, moves2 = 0;
        int curr1 = diag1[n / 2], curr2 = diag2[n / 2];

        for (int i = 0; i < n; i++)
        {
            moves1 += abs(diag1[i] - curr1);
            moves2 += abs(diag2[i] - curr2);
        }

        int ans = moves1 + moves2;
        cout << ans << endl;
    }
    return 0;
}