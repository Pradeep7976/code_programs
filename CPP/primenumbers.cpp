#include <iostream>
#include <vector>
#include <string>

using namespace std;

int setBits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
int resolveToZero(int x)
{
    int steps = 0;
    while (x > 0)
    {
        x = x % setBits(x);
        steps++;
    }
    return steps;
}

vector<int> resolvedArray(vector<char> &s)
{
    int n = s.size();
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x = (x << 1) + (s[i] - '0');
    }

    int setBitCount = setBits(x);

    vector<int> results(n);

    for (int i = 0; i < n; i++)
    {
        int flippedX = x;

        if (s[i] == '1')
        {
            flippedX -= 1 << (n - 1 - i);
        }
        else
        {
            flippedX += 1 << (n - 1 - i);
        }

        results[i] = resolveToZero(flippedX);
    }

    return results;
}

int main()
{
    // Example usage
    int n;
    cin >> n;
    vector<char> s(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }

    vector<int> result = resolvedArray(s);

    // Output the results
    for (int res : result)
    {
        cout << res << endl;
    }

    return 0;
}
