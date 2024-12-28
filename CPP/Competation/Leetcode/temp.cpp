#include <iostream>
#include <string>

using namespace std;



int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int result = minReplacementsToPalindrome(s1, s2);
    cout << result << endl;

    return 0;
}
