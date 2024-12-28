#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestSequenceFromCell(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int n) {
    if (i < 0 || i >= n || j < 0 || j >= n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int result = 1;
    
    if (i > 0 && (matrix[i][j] + 1 == matrix[i - 1][j]))
        result = max(result, 1 + longestSequenceFromCell(matrix, dp, i - 1, j, n));
    if (i < n - 1 && (matrix[i][j] + 1 == matrix[i + 1][j]))
        result = max(result, 1 + longestSequenceFromCell(matrix, dp, i + 1, j, n));
    if (j > 0 && (matrix[i][j] + 1 == matrix[i][j - 1]))
        result = max(result, 1 + longestSequenceFromCell(matrix, dp, i, j - 1, n));
    if (j < n - 1 && (matrix[i][j] + 1 == matrix[i][j + 1]))
        result = max(result, 1 + longestSequenceFromCell(matrix, dp, i, j + 1, n));

    return dp[i][j] = result;
}

int longestSequence(vector<vector<int>>& matrix, int n) {
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int result = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] == -1) {
                longestSequenceFromCell(matrix, dp, i, j, n);
            }
            result = max(result, dp[i][j]);
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int result = longestSequence(matrix, n);
    cout << result << endl;

    return 0;
}
