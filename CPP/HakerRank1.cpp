#include <iostream>

using namespace std;

int fibonacci(int n, int M)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return (fibonacci(n - 1, M) + fibonacci(n - 2, M) + (n - 1)) % M;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, M;
        cin >> n;
        cin >> M;

        int result = fibonacci(n, M);
        cout << result << endl;
    }

    return 0;
}
