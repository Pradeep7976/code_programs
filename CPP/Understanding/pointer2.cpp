#include <iostream>
using namespace std;
int main()
{
    int a;
    a = 1000;
    int *b; // Data type behind ' * ' is the the type of datatype we want to point
    b = &a;
    cout << *b << endl; //Here '*' is a dereferring the pointer
    cout << b;

    int ar[3] = {1, 2, 3, 4};
    int *f = ar;
}