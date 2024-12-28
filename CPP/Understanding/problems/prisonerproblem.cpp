
//   prisoners
//   choclates
//   distribution starts from

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void insertattail(int val, Node *&head)
{

    Node *n = new Node;
    if (head == NULL)
    {
        n->data = val;
        n->next = n;
        head = n;
        cout << n->data << " ";
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
    cout << n->data << " ";
}

void display(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp->next != head);

    cout << temp->data << " ";
    temp = temp->next;
}
int main()
{
    Node *head = NULL;
    cout << "number of prisoners" << endl;
    int n;
    // cin >> n;
    for (int i = 1; i <= 4; i++)
    {
        insertattail(i, head);
    }
    display(head);
    return 0;
}