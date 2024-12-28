#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
using namespace std;
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
// bool check_key(map < int, pair<int, bool> m, int key, int col)
// {
//     // Key is not present
//     if (m.find(key) == m.end())
//     {
//         return true;
//     }
//     else
//     {
//         int x = m[key].first;
//         if (x == col)
//         {
//             return false;
//         }
//         return true;
//     }
// }
// vector<int> getTopView(TreeNode<int> *root)
// {
//     map<int, pair<int, bool>> mp;
//     queue<pair<TreeNode<int> *, int>> q;
//     vector<int> ans;
//     q.push(make_pair(root, 0));
//     int level = 0;
//     int col = 0;
//     while (!q.empty())
//     {
//         TreeNode<int> *node = q.front().first;
//         q.pop();
//         int x = q.front().second;
//         if (check_key(m, node->val, level, col))
//         {
//             ans.push_back(node->val);
//             mp.insert(node->val, make_pair(col, false));
//         }
//         if (node->left)
//         {
//             q.push(make_pair(node->left, x - 1));
//         }
//         if (node->right)
//         {
//             q.push(make_pair(node->right, x + 1));
//         }
//     }
//     return ans;
// }
bool check_key(map<int, int> m, int key)
{
    // Key is not present
    if (m.find(key) == m.end())
        return false;

    return true;
}
vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    mp[root->val] = root;
    while (!q.empty())
    {
        TreeNode<int> *node = q.front().first;
        int x = q.front().second;
        q.pop();
        if (mp.find(x) == mp.end())
        {
            mp[x] = node->val;
        }
        if (node->left != NULL)
        {
            q.push(node->left, x - 1);
        }
        if (node->right != NULL)
        {
            q.push(node->right, x + 1);
        }
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
int main()
{

    return 0;
}