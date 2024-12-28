#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> elements(n);
    vector<int> indices(n);
    vector<int> result(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> elements[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> indices[i];
    }

    for (int i = 0; i < n; ++i)
    {
        result[indices[i]] = elements[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
