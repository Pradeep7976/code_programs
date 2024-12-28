#include <iostream>
using namespace std;
struct Node
{

    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void Preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
void Postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);

    Postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    /*


         1
      /    \
     2      7
   /   \   /  \
  5    7  7    5
    
    
    */
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(5);
    root->left->right = new Node(7);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    cout << "Preorder is ";
    Preorder(root);
    cout<<endl;
    cout << "Postorder is ";
    Postorder(root);
    cout<<endl;
    cout << "inorder is ";
    Inorder(root);

    return 0;
}

// 1 2 3 Base Hitted
// left completed
// entering right node
// Base Hitted
// right completed left completed
// entering right node
// 4 Base Hitted
// left completed
// entering right node
// Base Hitted
// right completed right completed left completed
// entering right node
// 5 6 Base Hitted
// left completed
// entering right node
// Base Hitted
// right completed left completed
// entering right node
// 7 Base Hitted
// left completed
// entering right node
// Base Hitted
// right completed right completed right completed