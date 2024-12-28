//runs in codecheif online ide

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
        // Node *left = NULL;         this creates local variable or assign the value locally
        // Node *right = NULL;
    }
};

int sumNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (root->data + sumNodes(root->left) + sumNodes(root->right));
}
int count(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (1 + count(root->left) + count(root->right));
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

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    cout << "Tree Building" << endl;
    root->right = new Node(7);
    root->right->right = new Node(5);
    root->right->left = new Node(7);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    cout << "Sum of nodes is ";
    cout << sumNodes(root);
    cout << endl;
    cout << "Number of nodes is ";
    cout << count(root);
    cout << endl;
    cout << "The inorder is";
    inorderprint(root);

    return 0;
}