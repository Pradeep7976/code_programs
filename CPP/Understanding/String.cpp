#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1 = "adcc";
    cout << s1[1];
    s1.erase(1,1);
    cout << s1[1];
    return 0;
}