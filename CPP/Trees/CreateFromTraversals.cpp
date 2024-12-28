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
    void displaymap(map<int, int> m)
    {
        for (auto x : m)
        {
            cout << x.first << " " << x.second;
        }
    }

public:
    map<int, int> createmap(vector<int> inorder)
    {
        map<int, int> m;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            m[inorder[i]] = i;
        }
        displaymap(m);
        return m;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> mp = createmap(inorder);
        return buildTreeUtil(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, mp);
    }
    TreeNode *buildTreeUtil(vector<int> &preorder, vector<int> &inorder, int pstart, int pend, int instart, int inend, map<int, int> m)
    {
        if (pstart > pend || instart > inend)
        {
            return NULL;
        }
        TreeNode *newnode = new TreeNode(preorder[pstart]);
        int ind = m[preorder[newnode->val]];
        int len = ind - instart;
        newnode->left = buildTreeUtil(preorder, inorder, pstart + 1, pstart + ind, instart, ind - 1, m);
        newnode->right = buildTreeUtil(preorder, inorder, pstart + ind + 1, pend, ind + 1, inend, m);
        return newnode;
    }
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root->val == val)
        {
            return root;
        }
        if (root->val > val)
        {
            searchBST(root->left);
        }
        else
        {
            searchBST(root->right);
        }
    }
};
int main()
{
    vector<int> v;
    return 0;
}