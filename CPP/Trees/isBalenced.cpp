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
    bool isBalanced(TreeNode *root)
    {
        ans = isBalancedUtil(root);
        return (ans != -1);
    }
    int isBalancedUtil(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = isBalancedUtil(root->left);
        int rh = isBalancedUtil(root->right);
        if (abs(lh - rh) > 1)
            return -1;
        return 1 + max(lh, rh);
    }
};
int main()
{

    return 0;
}