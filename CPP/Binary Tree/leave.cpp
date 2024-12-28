
//Not yet completed

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
    Node(int val)
    {
        data = val;
    }
};

void leaves(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->right == NULL && root->left == NULL)
    {
        cout << root->data << " ";
    }
    leaves(root->right);
    leaves(root->left);
}

void inorderprint(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
}
//      1
//    /   \
//   2     7
//  / \   / \
// 5   3 7   5
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->right->right = new Node(5);
    root->right->left = new Node(7);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    cout << "leaves are : ";
    leaves(root);
    cout << endl;
}
