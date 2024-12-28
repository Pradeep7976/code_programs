//
// https://www.codechef.com/SEP221D/problems/DISTNUMS

#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

vector<pair<int, int>> factors(pair<int, int> n)
{
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n.first; i++)
    {
        if (n.first % i == 0)
        {
            ans.push_back(make_pair(i, n.second));
        }
    }
    return ans;
}
void displayp(vector<pair<int, int>> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {

        cout << vect[i].first << " " << vect[i].second << endl;
    }
}
void display(vector<int> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {

        cout << vect[i] << " " << endl;
    }
}
void sumii(pair<int, int> fact, int n, int k)
{
    // if (flag == 0)
    // {
    //     k--;
    // }
    // flag = 1;
    if (fact.second == k)
    {
        return;
    }
    vector<pair<int, int>> fcts;
    fcts = factors(fact);
    for (int i = 0; i < fcts.size(); i++)
    {
        int answi = fcts[i].first * n;
        fcts[i].first = answi;
        fcts[i].second++;
        if (find(ans.begin(), ans.end(), answi) == ans.end())
        {
            ans.push_back(answi);
        }
        sumii(make_pair(fcts[i].first, fcts[i].second), answi, k);
    }
    // flag = 0;
}

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    // 	int n, k;
    // 	cin >> n;
    // 	cin >> k;
    // }
    // sumii(2, 2, 2);
    vector<pair<int, int>> v;
    // v = factors(make_pair(10, 1));
    sumii(make_pair(1, 0), 1, 5);
    display(ans);
    // displayp(v);
    cout << accumulate(ans.begin(), ans.end(), 0);
    return 0;
}
