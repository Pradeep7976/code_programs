//input
// 2
// 5 2 3
// 10 11 10 11 12
// 5 5 1
// 1 2 3 4 5

//output
// 23 21 21
// 15

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    // queue <int> a;
    int t;
    cout << "no of test cases" << endl;
    cin >> t;
    while (t != 0)
    {
        cout << "size of array" << endl;
        int r; //size of array
        cin >> r;
        int arr[r];
        cout << "size to treverse" << endl;
        int t; //size to treverse
        cin >> t;
        int k;
        cin >> k;
        for (int i = 0; i < r; i++)
        {
            cin >> arr[i];
        }
        int *start; //pointer to point an array
        int *end;
        int sum;
        start = arr;
        // end=arr[t];
        while (*end = arr[r])
        {
            for (int i = 0; i < t; i++)
            {
                sum = *start;
                start++;
            }
            cout << sum << endl;
        }

        t--;
    }
    return 0;
}