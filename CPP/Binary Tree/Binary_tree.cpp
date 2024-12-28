#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *right = NULL;
    Node *left = NULL;
    Node(int val)
    {
        data = val;
        Node *right = NULL;
        Node *left = NULL;
    }
};
int count(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    cout << "hi count";
    return count(root->left) + count(root->right) + 1;
}
void inorderprint(Node *root)
{
    if (root == NULL)
    {
        cout << "hi base";
        return;
    }
    cout << "hi inorderprint";
    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
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
    Node *root;
    root->data = 1;
    cout << "hi before";
    root->left = new Node(2);
    root->right = new Node(7);
    root->right->right = new Node(5);
    root->right->left = new Node(7);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    cout << "hi tree build completed";

    cout << count(root);
    inorderprint(root);
    return 0;
}