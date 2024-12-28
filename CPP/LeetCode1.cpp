#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
using namespace std;

bool canMakeSubsequence(string str1, string str2)
{
    int i = str1.length() - 1;
    int j = str2.length() - 1;
    while (i >= 0 && j >= 0)
    {
        char temp = str1[i];
        char nextchar;

        if (temp == 'z')
        {
            nextchar = 'a';
        }
        else
        {
            nextchar = temp+1;
        }
        if (nextchar == str2[j] || str1[i] == str2[j])
        {
            i--;
            j--;
        }
        else
        {
            i--;
        }
    }
    return j < 0;
}

int main()
{
    string str1 = "abc";
    string str2 = "ad";
    cout << canMakeSubsequence(str1, str2);
    return 0;
}