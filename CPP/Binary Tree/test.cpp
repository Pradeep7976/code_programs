#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {1, 3, 12, 7, 9, 6};
    sort(v.begin(), v.end());
    for (auto X : v)
    {
        cout << X << " ";
    }
    return 0;
}