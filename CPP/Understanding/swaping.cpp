#include <iostream>
using namespace std;

void swap(int **A, int **B)
{
    cout << "i am running by pointers";
    int temp;
    temp = **A;
    **A = **B;
    **B = temp;
}

void swap(int &A, int &B)
{
    cout << "i am running by refernce";
    int temp;
    temp = A;
    A = B;
    B = temp;
}

int main()
{

    int A = 10, B = 20;
    swap(A, B);
    cout << A << " " << B << endl;
    int *adu = &A;
    int *bdu = &B;
    swap(&adu,&bdu);
    cout << A << " " << B << endl;

    return 0;
}