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
    string serialize(TreeNode *root)
    {
        queue<TreeNode *> q;
        string s = "";
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curNode = q.front();
            q.pop();
            if (curNode == NULL)
            {
                s.append("#,");
            }
            else
            {
                s.append(to_string(curNode->val) + ",");
            }
            if (curNode != NULL)
            {
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        queue<TreeNode *> q;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
            {
                node->left = NULL;
            }
            else
            {
                TreeNode *leftnode = new TreeNode(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }
            getline(s, str, ',');
            if (str == "#")
            {
                node->right = NULL;
            }
            else
            {
                TreeNode *rightnode = new TreeNode(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};
int main()
{

    return 0;
}