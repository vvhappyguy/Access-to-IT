#include <iostream>
#include <limits>
#include <queue>

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
    int widthOfBinaryTree(TreeNode* root)
    {
        int width = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int n = q.size();
            int max_index = std::numeric_limits<int>::min(), min_index = std::numeric_limits<int>::max();
            while (n--)
            {
                TreeNode* tmp = q.front().first;
                int dist = q.front().second;
                q.pop();
                max_index = max(max_index, dist);
                min_index = min(min_index, dist);
                if (tmp->left)
                {
                    q.push({tmp->left, (long long)2 * dist + 1});
                }
                if (tmp->right)
                {
                    q.push({tmp->right, (long long)2 * dist + 2});
                }
            }
            width = max(width, max_index - min_index + 1);
        }
        return width;
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

    cout << solution.widthOfBinaryTree(&root) << endl;

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

    cout << solution.widthOfBinaryTree(&root) << endl;

    return 0;
}