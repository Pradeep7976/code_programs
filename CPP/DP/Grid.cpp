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
void vectordisplay(vector<vector<int>> v)
{
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int uniquePaths(int m, int n, vector<vector<int>> obgrid)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // return f1(m - 1, n - 1, dp);
    // int dp[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (obgrid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = left + up;
            }
        }
    }
    return dp[m - 1][n - 1];
}
int f1(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + f1(i - 1, j, dp, grid);
    int left = grid[i][j] + f1(i, j - 1, dp, grid);
    return dp[i][j] = min(left, up);
}
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // return uniquePaths(m, n, grid);
    return f1(m - 1, n - 1, dp, grid);
}
int minimumPathSumUtil(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == n - 1)
        return triangle[i][j];

    int down = triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(down, diagonal);
}

int minimumTotal(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return minimumPathSumUtil(0, 0, triangle, n, dp);
}

// int getMaxPathSumUtil(vector<vector<int>> &matrix, int i, int j, int n)
// {
//     if (i == n - 1)
//         return matrix[i][j];
//     if (i < 0 || j < 0 || i > n || j > n)
//         return 0;
//     int left = matrix[i][j] + getMaxPathSumUtil(matrix, i - 1, j, n);
//     int lr = matrix[i][j] + getMaxPathSumUtil(matrix, i, j + 1, n);
//     int right = matrix[i][j] + getMaxPathSumUtil(matrix, i + 1, j, n);
//     int maxi = (left, maxi);
//     maxi = max(maxi, lr);
//     maxi = max(right, maxi);
//     return maxi;
// }
int getMaxPathSumUtil(vector<vector<int>> &matrix, int i, int j, int m, vector<vector<int>> &dp)
{
    if (j < 0 || j >= m)
        return -1e9;
    if (i == 0)
        return matrix[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + getMaxPathSumUtil(matrix, i - 1, j, m, dp);
    int leftDiagonal = matrix[i][j] + getMaxPathSumUtil(matrix, i - 1, j - 1, m, dp);
    int rightd = matrix[i][j] + getMaxPathSumUtil(matrix, i - 1, j + 1, m, dp);
    int maxi = max(up, max(leftDiagonal, rightd));
    return dp[i][j] = maxi;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        maxi = max(maxi, getMaxPathSumUtil(matrix, n - 1, j, m, dp));
    }
    return maxi;
}

int main()
{
    int a, b;
    vector<vector<int>> v({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}});
    // cout << minPathSum(v);
    vectordisplay(v);

    return 0;
}