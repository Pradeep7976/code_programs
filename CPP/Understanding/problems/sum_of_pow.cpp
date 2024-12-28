
//https://www.hackerrank.com/challenges/the-power-sum/problem

#include <bits/stdc++.h>
using namespace std;

long long int pow(int p)
{
    long long int ans;
    return p * p;
}

vector<long long int> check(long long int p, long long int q, long int m)
{
    vector<long long int> v;
    // vector<long long int> v1;
    if (pow(p) + pow(q) == m)
    {
        v.push_back(p);
        v.push_back(q);
        return v;
    }
    check(p + 1, q - 1, m);
    return v;
}

int main()
{
    long int n;
    cin >> n;
    // long long int ans = pow(n);
    // cout << ans;
    vector<long long int >v=check(INT_MIN,INT_MAX,n);
    cout<<v[0]<<" "<<v[1];
    return 0;
}