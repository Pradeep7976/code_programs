//find the sum of all the possible subarrays take input from the user and equate it with the sums of all subarray 
//which subarry gives the sum output the atarting and ending element of that subarray
#include<iostream>
using namespace std;
int main()
{
    int n,sum;
    cout<<"size of array"<<endl;
    cin>>n;
    int arr[n];
    int s;
    cout<<"enter the elements of array"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"enter the key"<<endl;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            sum+=arr[j];
            if(sum==s)
            {
                cout<<i<<""<<j;
            }
        }
    }
    return 0;
}