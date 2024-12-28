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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mp;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            TreeNode *node = q.front().first;
            int x = q.front().second;
            q.pop();
            if ((mp.find(x) == mp.end()))
                mp[x] = node->val;

            if (node->left != NULL)
            {
                q.push({node->left, x + 1});
            }
            if (node->right != NULL)
            {
                q.push({node->right, x + 1});
            }
        }
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
int main()
{
    vector<int> v;
    return 0;
}