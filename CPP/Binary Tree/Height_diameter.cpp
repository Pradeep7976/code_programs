
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

int calcheight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int rightheight = calcheight(root->right);
    int leftheight = calcheight(root->right);
    return max(rightheight, leftheight) + 1;
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
    cout << calcheight(root);
}
