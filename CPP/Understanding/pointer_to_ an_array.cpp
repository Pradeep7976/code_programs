#include <iostream>
using namespace std;
int main()
{
    int r;
    cin >> r;
    int arr[r];
    for (int i = 0; i < r; i++)
    {
        cin >> arr[i];
    }
    int *ar; //pointer to point an array
    ar = arr;
    for (int i = 0; i < r; i++)
    {
        cout << *ar << " ";
        ar++;
    }
    return 0;
}