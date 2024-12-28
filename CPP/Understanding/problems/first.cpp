// Input:
// 2
// 1 2 4 5 6 9 9 9 9 9
// 1 2 3 3 3 3 3 5 9 10

// Output:
// 9
// 3
#include<iostream>

using namespace std;

int main()
{
    int a=0;
    int arr[10];
    for (int i=0;i<10;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<10;i++)
    {
        if (arr[i]=arr[i-1] )
        {
            a=arr[i];   
        }
    }
    cout<<a;
    return 0;
}