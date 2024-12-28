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
public
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int size = q.size();
            int mmin = q.front().second;
            int left, right;
            for (int i = 0; i < size; i++)
            {
                int curind = q.front().second - mmin;
                TreeNode *node = q.front().first;
                q.pop();
                if (i == 0)
                    left = curind;
                if (i == size - 1)
                    right = curind;
                if (node->left)
                {
                    q.push({node->left, curind * 2 + 1});
                }
                if (node->right)
                {
                    q.push({node->right, curind * 2 + 2});
                }
            }
            ans = max(ans, right - left + 1);
            pow()
        }
    }
    TreeNode *childrensum(TreeNode *root)
    {
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *node = root;
        while (!s.empty())
        {
            if (root != NULL)
            {
                s.push(node);
                node = node->left;
            }
            else
            {
                if (s.empty())
                    break;
                node = s.top();
                
            }
        }
    }
};
int main()
{
    vector<int> v;
    return 0;
}