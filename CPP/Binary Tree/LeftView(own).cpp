#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left = NULL;
    Node *right = NULL;
    Node(int data)
    {
        val = data;
    }
};
class solution
{
    vector<int> ans;
    void Leftview(Node *root)
    {
        while (!root)
        {
            ans.push_back(root->val);
            if (root->left)
            {
                root = root->left;
            }
            else
            {
                root->right;
            }
        }
    }
};
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
//   3     4
//    \    
//     5
int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->right = new Node(5);
    root->right = new Node(4);
    cout << "The left view is ";
    cout << root->data << " ";
    Leftview(root);
    cout << endl;
    cout << "Inorder is ";
    inorderprint(root);
    return 0;
}