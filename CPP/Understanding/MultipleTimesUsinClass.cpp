#include <iostream>

using namespace std;
class lol
{
private:
    int value = 1;

public:
    void show(int val)
    {
        cout << val + 1 << " lol" << endl;
    }
};
int main()
{
    int n;
    cout << "no of objects" << endl;
    cin >> n;
    lol *yo = new lol[n];
    yo[0].show(99);
    yo[1].show(100);
    yo[2].show(101);
    yo[3].show(102);

    return 0;
}