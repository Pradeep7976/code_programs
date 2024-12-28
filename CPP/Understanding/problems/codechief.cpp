/*
N = no of planes
M = different targets in enemy
co ordinates (base X, base Y)
base and targets are recognisd by ID
The first line contains three space separated integers N, M and T respectively.
The next N lines contain 3 integers denoting x coordinate, y coordinate and the ID of the air bases.
The next M lines contain 3 integers denoting x coordinate, y coordinate and the ID of the targets.
The last line contains two integers denoting the baseX and baseY coordinate.
"t = prime factor of manhattan distance"
"if ID is grater than largest prime factor then consider ID itself"
Time taken  to come back is same as for going // ==T
max time T
t should be lesser than T
*/
int manhattan(int arr[], int a, int ar[], int b)
{
    int v;
    int l;
    int r;
    l = (arr[0] - ar[0]);
    r = (arr[1] - ar[1]);
    if (l < 0)
    {
        l = l * -1;
    }
    if (r < 0)
    {
        r = r * -1;
    }
    v = r + b;
    if (v < 0)
    {
        return v * -1;
    }
    else
    {
        return v;
    }
}
//Have to find largest prime factor
//compare it with ID
//it wil become t
//check if 2 * t is less than T

#include <iostream>
using namespace std;
int main()
{
    int N;
    int M;
    int T;
    int arr[3];
    int k;
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }
    N = arr[1];
    M = arr[2];
    T = arr[3];
    int base[N];
    int target[M];
    for (int i = 0; i < N; i++)
    {
        cin >> base[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> target[i];
    }

    k = manhattan(base, N, target, M);
    cout << k;

    return 0;
}
