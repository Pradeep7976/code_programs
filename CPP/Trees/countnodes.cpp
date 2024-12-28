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
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lefth = findlh(root);
        int righth = findrh(root);
        if (lefth == righth)
        {
            return pow(2, lefth) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int findlh(TreeNode *node)
    {
        int lhe = 0;
        while (node)
        {
            lhe++;
            node = node->left;
        }
        return lhe;
    }
    int findrh(TreeNode *node)
    {
        int rhe = 0;
        while (node)
        {
            rhe++;
            node = node->right;
        }
        return rhe;
    }
};
int main()
{
    vector<int> v;
    return 0;
}