//if we want to convert a char(in the stack) into int we have to minus    '0'      this ascai value will covert the char into int

#include <iostream>
#include <stack>
using namespace std;

void converter(char v)
{
    v = v - '0';
    int n;
    n = v;
    cout << n;
}
int main()
{
    char h = '6';
    converter(h);

    return 0;
}