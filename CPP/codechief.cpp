#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N - i; ++j) {
            cout << "  ++"; 
        }
        cout << "* "; 
        if (i > 1 && i < N) {
            for (int j = 1; j <= i - 2; ++j) {
                cout << "  ";  
            }
            cout << "*"; 
        } else if (i == N) { 
            for (int j = 1; j <= i - 1; ++j) {
                cout << "* ";  
            }
        }
        cout << endl;
    }

    for (int i = N - 1; i >= 1; --i) {
        for (int j = 1; j <= N - i; ++j) {
        }
        cout << "* ";
        if (i > 1) {
            cout << "  ";
            for (int j = 1; j <= i - 2; ++j) {
                cout << "  "; 
            }
            cout << "*"; 
        }
        cout << endl;
    }

    return 0;
}
