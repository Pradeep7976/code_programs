#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        bool found = false;
        for (int i = 0; i < s.length(); i++)
        {
            bool check = false;
            for (int j = 0; j < s.length(); j++)
            {
                if (i != j)
                {
                    if (s[i] == s[j])
                    {
                        check = true;
                        break;
                    }
                }
            }
            if (!check)
            {

                return i;
            }
        }
        return -1;
    }
};
int main()
{
    string s="loveleetcode";
    //cin >> s;

    Solution sol;
    cout << sol.firstUniqChar(s);

    return 0;
}
