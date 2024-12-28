#include <bits/stdc++.h>
using namespace std;

bool canBobWin(int x, int y, vector<pair<int, int>> &alicePath, int n) {
    for (int i = 0; i <= n; i++) {
        if (x == alicePath[i].first && y == alicePath[i].second) {
            return false;
        }

        if (i < n) {
            int dx = alicePath[i + 1].first - alicePath[i].first;
            int dy = alicePath[i + 1].second - alicePath[i].second;
            
            // Try all possible moves for Bob
            if (canBobWin(x + 1, y, alicePath, i + 1) ||
                canBobWin(x - 1, y, alicePath, i + 1) ||
                canBobWin(x, y + 1, alicePath, i + 1) ||
                canBobWin(x, y - 1, alicePath, i + 1)) {
                return true;
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, b1, b2;
        cin >> n >> b1 >> b2;
        string s;
        cin >> s;

        int x = 0, y = 0;
        vector<pair<int, int>> alicePath(n + 1);
        alicePath[0] = {x, y};

        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') x++;
            else if (s[i] == 'L') x--;
            else if (s[i] == 'U') y++;
            else if (s[i] == 'D') y--;

            alicePath[i + 1] = {x, y};
        }

        if (canBobWin(b1, b2, alicePath, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
