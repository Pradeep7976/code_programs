#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};

void InsertAtTail(node **head, int val) //here we get head pointer by pointer reference so as to modify the pointer (if we get it by normally by refernce it will not change the pointer to which it is pointing to)
{                                       //head will not move if we get head normally(it will be still pointing to null)
    node *hosanode = new node();
    hosanode->data = val;
    hosanode->next = NULL;

    if (*head == NULL)
    {
        *head = hosanode;
        return;
    }
    node *temp = *head;

    while (temp->next != NULL)
    {

        temp = temp->next;
    }

    temp->next = hosanode;
}
void display(node **head)
{

    node *temp = *head;

    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    node *head = NULL;
    InsertAtTail(&head, 1);
    InsertAtTail(&head, 2);
    display(&head);

    return 0;
}