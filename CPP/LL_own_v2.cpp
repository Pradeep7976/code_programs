#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void InsertAtTail(node *&head, int val) //here we get head pointer by pointer reference so as to modify the pointer (if we get it by normally by refernce it will not change the pointer to which it is pointing to)
{                                       //head will not move if we get head normally(it will be still pointing to null)
    node *hosanode = new node();
    hosanode->data = val;
    hosanode->next = NULL;

    if (head == NULL)
    {
        head = hosanode;
        return;
    }
    node *temp = head;

    while (temp->next != NULL)
    {

        temp = temp->next;
    }

    temp->next = hosanode;
}
void InsertAtMiddle(node *prvnode, int val)
{
    node *hodsanode = new node();
    node *temp = prvnode->next;
    prvnode->next = hodsanode;
    hodsanode->next = temp;
}
void InsertAtHead(node *&head, int val)
{
    node *hosanode = new node();
    node *temp = head;
    hosanode->data = val;
    hosanode->next = temp;
    /* node*head*/ head = hosanode;
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
void search(node *head, int m)
{
    int n = 1;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data = m)
        {
            cout << "The element is at the node " << n << endl;
            return;
        }
        n++;
    }
    cout << "the required no is absent" << endl;
}

int main()
{
    node *head = NULL;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtHead(head, 3);
    display(head);
    search(head, 3);
    // cout << "hi" << head->data << endl;

    return 0;
}