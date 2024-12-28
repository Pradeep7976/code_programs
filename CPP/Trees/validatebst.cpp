#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
using namespace std;
template <typename T>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{

    bool isValidBST(TreeNode *root)
    {
        return isValidBSTUtil(root);
    }
    bool isValidBSTUtil(TreeNode *root, TreeNode *minnode, TreeNode *maxnode)
    {

        if (root == NULL)
        {
            return true;
        }

        if (root->right && root->right->val < root->val || root->right->val == root->val)
        {
            return false;
        }

        if (root->left != NULL)
        {
            if (root->left->val > root->val || root->left->val == root->val)
            {
                return false;
            }
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
int main()
{
    TreeNode *root;
    return 0;
}