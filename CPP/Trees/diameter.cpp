#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
using namespace std;

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
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxi = 0;
        diameterOfBinaryTreeUtil(root, maxi);
        return maxi;
    }
    int diameterOfBinaryTreeUtil(TreeNode *node, int &maxi)
    {
        if (node == NULL)
            return 0;
        int lh = diameterOfBinaryTreeUtil(node->left, maxi);
        int rh = diameterOfBinaryTreeUtil(node->right, maxi);
        maxi = max(maxi, lh + rh);
        return 1 + max(lh, rh);
    }

    bool isValidBST(TreeNode *root)
    {
        return isValidBSTUtil(root, LONG_MIN, );
    }
    bool isValidBSTUtil(TreeNode *root, long minval, long maxval)
    {
        if (root == NULL)
            return true;
        if (root->val >= maxval || root->val <= minval)
            return false;
        return isValidBSTUtil(root->left, minval, root->val) &&
               isValidBSTUtil(root->right, root.val, maxval);
    }
};
int main()
{
    vector<int> v;
    return 0;
}