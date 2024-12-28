#include <iostream>
#define pi 3.14
#define itratoru 0
using namespace std;

int areaOfCircle(int rad)
{
    return pi * rad * rad;
}

//not yet done

// int timesrunning(int k)
// {
//     for (int i = 0; i < k; i++)
//     {
//         itratoru++;
//     }
//     return itratoru + 1;
// }
int main()
{
    int radi;
    cout << " enter radius " << endl;
    cin >> radi;

    cout << areaOfCircle(radi);
    cout << "no of times running = ";
    cout << timesrunning(30);
    cout << itratoru;
    return 0;
}