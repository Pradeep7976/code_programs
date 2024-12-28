//passing an array into a function and taking output

#include <iostream>
using namespace std;
void func(int a[], int b)
{
    for (int j = 0; j < b; j++)
    {
        cout << a[j] << endl;
    }
}
int main()
{
    int n;
    cout << "enter the number of array elements" << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    func(arr, n);

    return 0;
}
