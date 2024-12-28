#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int search(int preorder[], int curr, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (curr = preorder[i])
        {
            return i;
        }
    }
    return -1;
}
Node *BuildTreeByPreorder(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    int curr = preorder[idx];
    Node *node = new Node(curr);
    idx++;

    int pos = search(preorder, curr, start, end);
    if (start == end)
    {
        return node;
    }
    node->left = BuildTreeByPreorder(preorder, inorder, start, pos - 1);
    node->right = BuildTreeByPreorder(preorder, inorder, pos + 1, end);
    return node;
}
void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main()
{
    int Preorder[] = {1, 2, 4, 3, 5};
    int Inorder[] = {4, 2, 1, 5, 3};
    Node *root = BuildTreeByPreorder(Preorder, Inorder, 0, 4);
    printInorder(root);
    return 0;
}
