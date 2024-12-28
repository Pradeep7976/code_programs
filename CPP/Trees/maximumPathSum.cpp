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
    // int maxi = INT_MIN;
    int sum = INT_MIN;
    int maxPathSum(TreeNode *root)
    {
        maxPathSumUtil(root, sum);
        return sum;
    }
    int maxPathSumUtil(TreeNode *node, int &sum)
    {
        if (node == NULL)
            return 0;

        int lsum = max(0, maxPathSumUtil(node->left, sum));
        int rsum = max(0, maxPathSumUtil(node->right, sum));
        sum = max(sum, lsum + node->val + rsum);
        cout << node->val << " " << lsum << " " << rsum << " " << sum << endl;
        return node->val + max(lsum, rsum);
    }
};
int main()
{

    return 0;
}