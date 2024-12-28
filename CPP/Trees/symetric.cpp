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
    bool isSymmetric(TreeNode *root)
    {
        return isSymmetricUtil(root->left, root->right);
    }
    bool isSymmetricUtil(TreeNode *left, TreeNode *right)
    {
        if (left == NULL || right == NULL)
        {
            return left == right;
        }
        if (left->val != right->val)
        {
            return false;
        }
        return isSymmetricUtil(left->left, right->right) && isSymmetricUtil(left->right, right->left);
    }
};
int main()
{
    vector<int> v;
    return 0;
}