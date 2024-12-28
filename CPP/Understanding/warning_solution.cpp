//warning: control reaches end of non-void function [-Wreturn-type]




//if this warning comes in any of the functions then we should add a garbage return at the end of the program



//for example


#include <bits/stdc++.h>
using namespace std;

vector<int> yoyo(int arr[], int n, int m)
{
    vector<int> v;
    vector<int>v1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((arr[i] + arr[j]) == m)
            {
                v.push_back(i+1);
                v.push_back(j+1);
                return v;                                  //here we want v to be returned so to remove warning        
            }
        }
    }
    return v1;                                            //garbage vector v1 is created and returned but program will return in for loop itself to 
                                                          //to remove warning we do this
}

int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        int m, n;
        cin >> m;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> v(2);
        v = yoyo(arr, n, m);
        for (auto x : v)
        {
            cout << x << " ";
        }
        t--;
    }

    return 0;
}