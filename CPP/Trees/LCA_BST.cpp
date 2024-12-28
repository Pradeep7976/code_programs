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
        if (root == NULL)
            return NULL;
        int curval = root->val;
        if (curval < p->val && curval < q->val)
            return lowestCommonAncestor(root->right, p, q);
        if (curval > p->val && curval > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};
int main()
{
    vector<int> v;
    return 0;
}