#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};
void InsertAtTail(node *&head, int value)
{
    node *n = new node(value);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void insertAthead(node *&head, int value)
{
    node *n = new node(value);
    n->next = head;
    head = n;
}
int main()
{
    // int m;
    // cout << "How many elements in linked list" << endl;
    // cin >> m;
    node *head = NULL;
    // for (int i = 0; i < m; i++)
    // {
    //     InsertAtTail(head, i+1);
    // }

    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);

    display(head);

    return 0;
}
