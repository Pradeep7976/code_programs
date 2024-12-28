#include <iostream>
using namespace std;
class stack
{
    int *arr;
    int top;
    int n = 999;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "No element to show " << endl;
            return 1;
        }
        cout << arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};
int main()
{
    stack st;
    int n;
    cout << "enter the no of elements stack" << endl;
    cin >> n;
    cout << "enter the elements of stack" << endl;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        st.push(data);
    }
    // cout << st.Top;
    return 0;
}