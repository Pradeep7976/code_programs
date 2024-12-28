#include <bits/stdc++.h>
#include <limits>
#include <vector>
using namespace std;

vector<int> breakingRecords(vector<int> scores)
{
    int first;
    int maxim = INT_MIN;
    int best = 0;
    int worst = 0;
    vector<int> res;
    first = scores[0];
    for (auto x : scores)
    {
        if (x == maxim || x == first)
        {
            continue;
        }
        if (x > maxim)
        {

            maxim = x;
            best++;
            res.push_back(best);
        }
        else
        {
            res.push_back(99);
        }
        if (x < first)
        {
            worst++;
            res.push_back(69);
        }
    }
    res.push_back(0);
    res.push_back(0);
    res.push_back(0);
    res.push_back(best - 1);
    res.push_back(worst);
    return res;
}

int main()
{
    int g;
    cin >> g;
    cout << "elements of array" << endl;
    vector<int> scores(g);
    for (int i = 0; i < g; i++)
    {
        int e;
        cin >> e;
        scores.push_back(e);
    }
    vector<int> sd;
    sd = breakingRecords(scores);
    for (auto x : sd)
    {
        cout << x << " ";
    }
    return 0;
}