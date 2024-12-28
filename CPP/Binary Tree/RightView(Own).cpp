

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

void RightView(Node *root)
{
    // if (root->right == NULL && root->left == NULL)
    // {
    //     cout << "base hitted";
    //     return;
    // }
    if (root == NULL)
    {
        return;
    }
    if (root->right != NULL)
    {
        cout << root->right->data << " ";
    }

    if (root->right == NULL)
    {
        cout << root->left->data;
    }

    RightView(root->right);
}

void inorderprint(Node *root)
{
    if (root == NULL)
    {
        cout << "base hitted";
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
    cout << "The Right view of tree is " << endl;
    cout << root->data << " ";
    RightView(root);
    cout << endl;
    cout << "Inorder is ";
    inorderprint(root);
}
