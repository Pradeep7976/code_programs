#include <bits/stdc++.h>
using namespace std;

string getSmallestString(string word, string substr) {
    int n = word.size();
    int m = substr.size();
    string result = "";
    bool found = false;

    for (int i = 0; i <= n - m; ++i) {
        string temp = word;

        bool canPlace = true;
        for (int j = 0; j < m; ++j) {
            if (temp[i + j] != '?' && temp[i + j] != substr[j]) {
                canPlace = false;
                break;
            }
        }

        if (canPlace) {
            for (int j = 0; j < m; ++j) {
                temp[i + j] = substr[j];
            }
            for (int k = 0; k < n; ++k) {
                if (temp[k] == '?') temp[k] = 'a';
            }

            if (!found || temp < result) {
                result = temp;
                found = true;
            }
        }
    }

    return found ? result : "-1";
}

int main() {
    string word, substr;
    cin >> word >> substr;
    cout << getSmallestString(word, substr) << endl;
    return 0;
}
