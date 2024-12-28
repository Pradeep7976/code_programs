#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
using namespace std;
int main()
{
    priority_queue<int, vector<int>> pq; //Max heap;
    pq.push(2);
    pq.push(5);
    pq.push(1);
    cout << pq.top();
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(2);
    pq1.push(5);
    pq1.push(1);
    cout << endl
         << pq1.top();
    return 0;
}