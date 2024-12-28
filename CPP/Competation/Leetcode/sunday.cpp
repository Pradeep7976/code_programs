#include <iostream>
#include <vector>

using namespace std;

int get_steps(vector<int> &a, int K)
{
    int steps = 0;
    int current_water = K;
    int N = a.size();

    for (int i = 0; i < N; ++i)
    {
        if (current_water < a[i])
        {
            steps += (i * 2);
            current_water = K;
        }
        current_water -= a[i];
        steps++;
    }

    return steps;
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    int K;
    cin >> K;

    int result = get_steps( a, K);
    cout << result << endl;

    return 0;
}
