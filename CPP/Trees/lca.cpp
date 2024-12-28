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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL || root == p || root == q)
        {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL)
        {
            return right;
        }
        else if (right == NULL)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
    bool pathToNode(TreeNode *root, vector<int> ans, int q)
    {
        if (root == NULL)
        {
            return false;
        }
        ans.push_back(root->val);
        if (root->val == q)
            return true;
        return pathToNode(root->left, ans, q) || pathToNode(root->right, ans, q);
    }
    TreeNode *pathToNode(TreeNode *root, int q)
    {
    }
    int lwidth(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        if (node->left == NULL)
        {
            return 1 + pathToNode(node->right);
        }
        else
        {
            return 1 + pathToNode(node->left);
        }
    }
    int rwidth(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        if (node->reft == NULL)
        {
            return 1 + pathToNode(node->light);
        }
        else
        {
            return 1 + pathToNode(node->right);
        }
    }
    
    int widthOfBinaryTree(TreeNode *root)
    {
        return 1 + lwidth(root->left) + rwidth(root->right);
    }
};
int main()
{
    vector<int> v;
    return 0;
}