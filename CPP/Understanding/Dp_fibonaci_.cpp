#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long int
using namespace std;

const int N=1e5+2,MOD =1e9+7;

//Normal recursive function
// int fib(int n)
// {
//     if (n == 0)
//         return 0;
//     if (n == 1)
//         return 1;
//     if (n == 2)
//         return 1;
//     return fib(n-1)+fib(n-2);
// }

//By dp

int dp[N];

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    if(dp[n]!=-1)
    return dp[n];
   
    dp[n]= fib(n-1)+fib(n-2);
    return dp[n];
}

int main()
{
    int n=10;
    // cin >> n;
    rep(i,0,N)
    {
        dp[i]=-1;
    }
    cout<<"fib by dp is "<<fib(n);
    return 0;
}