#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ll long long int
using namespace std;
vector<int> keys;
bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    bool flag = false;
    vector<int> temp = rooms[0];
    for (int i = 0; i < rooms.size(); i++)
    {
        temp = rooms[i];

        for (int j = 0; j < rooms[i].size(); j++)
        {
            cout << temp[j] << " ";
            keys.push_back(temp[j]);
        }
        cout << endl;
        if (binary_search(keys.begin(), keys.end(), i + 1))
        {
            continue;
        }
        else
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        return false;
    }
    cout << "tes" << endl;
    return true;
}
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> largestValues(TreeNode *root)
{
    queue<TreeNode *> que;
    vector<int> ans;
    que.push(root);
    while (!que.empty())
    {
        int n = que.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, que.front()->val);
            que.pop();
        }

        ans.push_back(maxi);

        if (que.front()->left != nullptr)
        {
            que.push(que.front());
            que.pop();
        }
        if (que.front()->right != nullptr)
        {
            que.push(que.front());
            que.pop();
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {{{1}, {2}, {3}, {}}};
    // vector<vector<int>> grid = {{{1, 3}, {3, 0, 1}, {2}, {0}}};
    if (canVisitAllRooms(grid))
    {
        cout << "Y";
    }
    else
    {
        cout << "N";
    }
    return 0;
}