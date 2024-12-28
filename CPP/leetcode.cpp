#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> heights;
    while (cin >> n) {
        heights.push_back(n);
    }

    int longest_start = 0, longest_end = 0;
    int current_start = 0, current_peak = 0;
    int i = 0;
    
    while (i < heights.size() - 1) {
        while (i < heights.size() - 1 && heights[i] < heights[i + 1]) {
            i++;
        }
        current_peak = i;

        while (i < heights.size() - 1 && heights[i] > heights[i + 1]) {
            i++;
        }
        int current_end = i;

        if (current_start < current_peak && current_peak < current_Send) {
            if ((current_end - current_start) > (longest_end - longest_start)) {
                longest_start = current_start;
                longest_end = current_end;
            }
        }
        if (i < heights.size() - 1) {
            current_start = i;
        }
    }

    for (int i = longest_start; i <= longest_end; ++i) {
        cout << heights[i] << " ";
    }

    return 0;
}
