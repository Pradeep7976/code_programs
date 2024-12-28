#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to insert element into the queue
    void insert(queue<int> &q, int k)
    {
        q.push(k);
    }
    int a = 0;
    int findFrequency(queue<int> &q, int k)
    {
        int a = 0;
        while (!q.empty())
        {
            if (q.front() == k)

            {
                a++;
                q.pop();
            }
            q.pop();
        }
        return a;
    }
};

int main()
{
    int testcase;
    cout << "test cases" << endl;
    cin >> testcase;
    while (testcase-- > 0)
    {
        queue<int> q;
        int n, k;
        cout << "no of elements of the queue" << endl;
        cin >> n;

        Solution obj;
        cout << "elements of queue" << endl;
        for (int i = 0; i < n; i++)

        {
            cin >> k;
            obj.insert(q, k);
        }
        int m;
        cout << "number of freequncy elements " << endl;
        cin >> m;

        for (int i = 0; i < m; i++)
        {
            cout << "frequenct is ";
            cin >> k;
            int f = obj.findFrequency(q, k);
            if (f != 0)
            {
                cout << f << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}