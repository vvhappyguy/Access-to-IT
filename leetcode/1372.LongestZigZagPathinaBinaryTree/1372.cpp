#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
public:
    int longestZigZag(TreeNode* root)
    {
        size_t maxStep = 0;
        dfs(root, true, 0, maxStep);
        dfs(root, false, 0, maxStep);
        return maxStep;
    }

    void dfs(TreeNode* node, bool side, int step, size_t& maxStep)
    {
        if (node == nullptr)
            return;
        if (step > maxStep)
            maxStep = step;
        if (side)
        {
            dfs(node->left, !side, step + 1, maxStep);
            dfs(node->right, side, 1, maxStep);
        }
        else
        {
            dfs(node->right, !side, step + 1, maxStep);
            dfs(node->left, side, 1, maxStep);
        }
        return;
    }
};

int main()
{
    Solution solution;

    TreeNode root;
    TreeNode a;
    TreeNode b;
    TreeNode aa;
    TreeNode ab;
    root.val = 0;
    root.left = &a;
    root.right = &b;
    a.val = 1;
    a.left = &aa;
    a.right = &ab;
    aa.val = 3;
    ab.val = 4;
    b.val = 2;

    cout << solution.longestZigZag(&root) << endl;

    root.val = 0;
    root.left = &a;
    a.val = 1;
    a.left = &aa;
    a.right = &ab;
    ab.left = &b;
    b.right = &aa;
    aa.val = 3;
    ab.val = 4;
    b.val = 2;

    cout << solution.longestZigZag(&root) << endl;

    return 0;
}