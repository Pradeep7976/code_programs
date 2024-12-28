//for sorting we must include the header "algorithm"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    //for output
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << endl;
    }

    vector<int>::iterator it;
    for (it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << endl;
    }
    for (auto element : v1)
    {
        cout << element << endl;
    }
    v1.pop_back(); //12(3 will be poped)

    vector<int> v2(3); // 3 ie the size of the vector can be pre difined
    // for (int i = 0; i < 3; i++)
    // {
    //     int h;
    //     cin >> h;
    //     v2.push_back(h);
    // }

    // for (auto element : v2)
    // {
    //     cout << element << endl;
    // }
    v2.push_back(55);
    v2.push_back(155);
    v2.push_back(555);
    swap(v1, v2);
    sort(v1.begin(), v1.end()); //for sorting we must include the header "algorithm"
    for (auto X : v1)
    {
        cout << X << " ";
    }

    return 0;
}