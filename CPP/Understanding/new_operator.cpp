#include <iostream>

using namespace std;

int main()
{
    // int f;
    int k;
    cin >> k;
    int *f = new int(k); //dynamic allocation of memory
    //for an dynamic array
    int n;
    cout << "size of dynamic array" << endl;

    int *yo = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> yo[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << yo[i] << " ";
    }
    return 0;
    // int *f =new int();
    // *f=9;
    // cout<<*f;
}
