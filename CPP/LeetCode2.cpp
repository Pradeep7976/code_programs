#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getMinLength(vector<int> &arr)
{
    int m = *min_element(arr.begin(), arr.end());
    int m_count = count(arr.begin(), arr.end(), m);

    if (m_count == 1 || any_of(arr.begin(), arr.end(), [m](int x)
                               { return x % m != 0; }))
    {
        return 1;
    }
    else
    {
        return ceil(static_cast<double>(m_count) / 2);
    }
}

int main()
{
    int n = 2;
    vector<vector<int>> c(n, vector<int>(n));
    vector<vector<int>> a({{1, 2}, {3, 4}});
    vector<vector<int>> b({{5, 4}, {1, 2}});
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}