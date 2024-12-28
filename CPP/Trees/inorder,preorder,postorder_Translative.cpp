


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
    vector<int> preorder(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();
            if (node->right != NULL)
                s.push(node->right);
            ans.push_back(node->val);
            if (node->left != NULL)
                s.push(node->left);
        }
        return ans;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;

        stack<TreeNode *> s;
        TreeNode *node = root;
        while (true)
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
                ans.push_back(node->val);
                s.pop;
                node = node->right;
            }
        }

        return ans;
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s1.push(root);
        while (!s1.empty())
        {
            root = s1.top();
            s1.pop();
            s2.push(root);
            if (root->left != NULL)
            {
                s1.push(root->left);
            }
            if (root->right != NULL)
            {
                s1.push(root->right);
            }
        }
        while (!s2.empty())
        {
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        bool flag = false;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                flag = !flag;
            }
            if (flag)
                ans.push_back(level);
            else
            {
                reverse(ans.begin(), ans.end());
                ans.push_back(level);
            }
        }
    }
};
int main()
{

    return 0;
}