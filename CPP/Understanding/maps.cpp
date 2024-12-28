#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define vi vector<int>
using namespace std;
int main()
{
    //declaration
    map<int, string> m;

    //we can append data as

    m[1] = "abc"; //here the one in square brackets is key and one after =  is value
    m[2] = "adc";
    m[3] = "adb";

    //we can also append by making pairs

    m.insert({4, "acb"}); //this is a short form of

    //another method
    m.insert(make_pair(5, "acd")); //    {}    represents makepair

    //iterating by making a iterator
    map<int, string>::iterator it;

    //giving output
    for (it = m.begin(); it != m.end(); ++it)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }

    //without iterator
    for (auto &pr : m) // for (auto pr : m) can also be used
    {
        cout << pr.first << " " << pr.second << endl;
    }

    //some extra functions

    auto it = m.find(3);
    cout << (*it).second;
    return 0;
}