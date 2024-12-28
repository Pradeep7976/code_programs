#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSumAfterRemovingAdjacents(vector<int> &arr)
{
    int result = 0;

    while (!arr.empty())
    {
        auto min_it = min_element(arr.begin(), arr.end());
        int min_index = distance(arr.begin(), min_it);
        int min_element = *min_it;

        result += min_element;

        if (min_index > 0 && min_index < arr.size() - 1)
        {
            arr.erase(arr.begin() + min_index - 1, arr.begin() + min_index + 2);
        }
        else if (min_index == 0)
        {
            arr.erase(arr.begin(), arr.begin() + 2);
        }
        else if (min_index == arr.size() - 1)
        {
            arr.erase(arr.end() - 2, arr.end());
        }
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    // vector<int> arr = {6,4,9,10,34,56,54}; // Example input
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minSumAfterRemovingAdjacents(arr) << endl;
    return 0;
}
