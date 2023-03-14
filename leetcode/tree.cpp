#include <algorithm>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#include "header/struct.hpp"

void printTree(TreeNode* root, string prefix);

void step(TreeNode* node, int sum, int target, vector<int> path, vector<vector<int>>& result)
{
    if (node == nullptr)
    {
        return;
    }
    path.push_back(node->val);
    if (node->left == nullptr && node->right == nullptr)
    {
        if (sum + node->val == target)
        {
            result.push_back(path);
        }
        return;
    }

    if (node->left)
    {
        sum += node->val;
        step(node->left, sum, target, path, result);
    }
    if (node->right)
    {
        sum += node->val;
        step(node->right, sum, target, path, result);
    }
    return;
}

// lc 112
bool hasPathSum(TreeNode* root, int targetSum)
{
    if (root == nullptr)
        return false;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (targetSum - root->val == 0)
        {
            return true;
        }
    }
    targetSum -= root->val;
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

// lc 104
int max(int a, int b)
{
    return a > b ? a : b;
}

// int maxDepthStep(TreeNode *root, int maxVal) {
//   if (root == nullptr) return 0;
//   maxVal += 1;
//   return max(maxVal, max(maxDepthStep(root->left, maxVal),
//                          maxDepthStep(root->right, maxVal)));
// }

// int maxDepth(TreeNode *root) { return maxDepthStep(root, 0); }

// From lc
int maxDepth(TreeNode* root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// lc 100
bool isSameTree(TreeNode* p, TreeNode* q)
{
    if ((p == nullptr) && (q == nullptr))
    {
        return true;
    }
    else if (p != nullptr && q == nullptr)
    {
        return false;
    }
    else if (q != nullptr && p == nullptr)
    {
        return false;
    }
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->left, q->left);
}

// lc 1379
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
{
    if (original == nullptr)
    {
        return nullptr;
    }
    if (target == original)
    {
        return cloned;
    }
    TreeNode* res = nullptr;
    res = getTargetCopy(original->left, cloned->left, target);
    if (res != nullptr)
    {
        return res;
    }
    res = getTargetCopy(original->right, cloned->right, target);
    return res;
}

// lc 1302
// Optimize with changing map into to ref ints :)
void step1302(TreeNode* root, map<int, int>& sum, int level)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        if (sum.size() != 0)
        {
            if (sum.begin()->first < level)
            {
                sum.clear();
                sum[level] = root->val;
            }
            else if (sum.begin()->first == level)
            {
                sum[level] += root->val;
            }
        }
        else
        {
            sum[level] = root->val;
        }
    }
    else
    {
        step1302(root->left, sum, level + 1);
        step1302(root->right, sum, level + 1);
    }
    // std:cout << level << ' ' << sum[level] << endl;
    return;
}

int deepestLeavesSum(TreeNode* root)
{
    map<int, int> sumByLevels;
    step1302(root, sumByLevels, 0);
    return sumByLevels.begin()->second;
}

// lc 938
int rangeSumBST(TreeNode* root, int low, int high)
{
    if (root == nullptr)
    {
        return 0;
    }
    int val = root->val;
    if (val > high || val < low)
    {
        val = 0;
    }
    return val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

// lc 1038 and 538
int step1038(TreeNode* root, int added)
{
    if (root == nullptr)
    {
        return 0;
    }
    int val = step1038(root->right, added);
    int save = root->val;
    root->val += val + added;
    val += save;
    val += step1038(root->left, val + added);

    return val;
}
TreeNode* bstToGst(TreeNode* root)
{
    // Bad solution
    step1038(root, 0);
    return root;
}
void start1038()
{
    TreeNode root;
    TreeNode a;
    TreeNode b;
    TreeNode aa;
    TreeNode ab;
    root.val = 3;
    root.left = &a;
    root.right = &b;
    a.val = 1;
    a.left = &aa;
    a.right = &ab;
    aa.val = 0;
    ab.val = 2;
    b.val = 4;
    // ...
    printTree(&root, "");
    bstToGst(&root);
    printTree(&root, "");
}

// lc 1315
int step1315(TreeNode* root, int parent, int grandparent)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (grandparent % 2 == 0)
    {
        return root->val + step1315(root->left, root->val, parent) + step1315(root->right, root->val, parent);
    }
    return step1315(root->left, root->val, parent) + step1315(root->right, root->val, parent);
}

int sumEvenGrandparent(TreeNode* root)
{
    return step1315(root, -1, -1);
}

// lc 700
TreeNode* searchBST(TreeNode* root, int val)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->val == val)
    {
        return root;
    }
    else if (root->val > val)
    {
        return searchBST(root->left, val);
    }
    return searchBST(root->right, val);
}

void start700()
{
    TreeNode root;
    TreeNode a;
    TreeNode b;
    TreeNode aa;
    TreeNode ab;
    root.val = 3;
    root.left = &a;
    root.right = &b;
    a.val = 1;
    a.left = &aa;
    a.right = &ab;
    aa.val = 0;
    ab.val = 2;
    b.val = 4;

    cout << "start700" << endl;
    std::cout << (searchBST(&root, 0) == &aa) << endl;
    std::cout << (searchBST(&root, 4) == &b) << endl;
    std::cout << (searchBST(&root, 5) == nullptr) << endl;
}

// lc 2331
bool evaluateTree(TreeNode* root)
{
    if (root->val == 2)
    {
        return evaluateTree(root->left) || evaluateTree(root->right);
    }
    else if (root->val == 3)
    {
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
    else
    {
        return root->val == 1;
    }
}

// lc 98
bool step98(TreeNode* root, TreeNode* min, TreeNode* max);
bool isValidBST(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr)
        return true;
    return step98(root, nullptr, nullptr);
}

bool step98(TreeNode* root, TreeNode* min, TreeNode* max)
{
    if (root == nullptr)
        return true;
    if ((min != nullptr && root->val <= min->val) || (max != nullptr && root->val >= max->val))
        return false;
    return step98(root->left, min, root) && step98(root->right, root, max);
}
void start98()
{
    TreeNode root;
    TreeNode a;
    TreeNode b;
    TreeNode aa;
    TreeNode ab;
    root.val = 3;
    root.left = &a;
    root.right = &b;
    a.val = 1;
    a.left = &aa;
    a.right = &ab;
    aa.val = 0;
    ab.val = 2;
    b.val = 4;

    cout << "start98" << endl;
    cout << isValidBST(&root) << endl;
    aa.val = 100;
    cout << isValidBST(&root) << endl;

    // case 1 : [5,4,6,null,null,3,7] - false
    root.val = 5;
    root.left = &b;
    root.right = &a;
    a.val = 6;
    aa.val = 3;
    ab.val = 7;
    b.val = 4;
    cout << isValidBST(&root) << endl;
}

// lc 94
void step94(TreeNode* root, vector<int>& vec)
{
    if (root == nullptr)
    {
        return;
    }
    step94(root->left, vec);
    vec.push_back(root->val);
    step94(root->right, vec);
}

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> res;
    step94(root, res);
    return res;
}

void start94()
{
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

    vector vec = inorderTraversal(&root);
    for (auto& v : vec)
    {
        cout << v << ' ';
    }
    cout << endl;
}

// lc 876
ListNode* middleNode(ListNode* head)
{
    ListNode* res = head;
    ListNode* last = head;
    bool updateRes = false;
    while (last != nullptr)
    {
        // cout << last->val << " ";
        if (updateRes)
        {
            res = res->next;
        }
        updateRes = !updateRes;
        last = last->next;
    }
    return res;
}

void start876()
{
    std::array<ListNode, 10> nodes10;
    std::array<ListNode, 9> nodes9;

    for (size_t i = 0; i < nodes10.size() - 1; ++i)
    {
        nodes10[i] = i;
        nodes10[i].next = &nodes10[i + 1];
    }
    nodes10[nodes10.size() - 1] = nodes10.size() - 1;

    for (size_t i = 0; i < nodes9.size() - 1; ++i)
    {
        nodes9[i] = i;
        nodes9[i].next = &nodes9[i + 1];
    }
    nodes9[nodes9.size() - 1] = nodes9.size() - 1;

    cout << middleNode(&nodes10[0])->val << endl;
    cout << middleNode(&nodes9[0])->val << endl;
}

// lc 109
pair<ListNode*, ListNode*> middleNodeAndPrev(ListNode* head)
{
    ListNode* res = head;
    ListNode* last = head;
    ListNode* prev = nullptr;
    bool updateRes = false;
    while (last != nullptr)
    {
        // cout << last->val << " ";
        if (updateRes)
        {
            prev = res;
            res = res->next;
        }
        updateRes = !updateRes;
        last = last->next;
    }
    return {prev, res};
}

TreeNode* sortedListToBST(ListNode* head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    TreeNode* root = new TreeNode();
    if (head->next == nullptr)
    {
        root->val = head->val;
        return root;
    }
    pair<ListNode*, ListNode*> res = middleNodeAndPrev(head);

    ListNode* prev = res.first;
    ListNode* middle = res.second;
    if (prev == nullptr)
    {
        return nullptr;
    }
    // cout << head->val << ':' << res.first->val << ':' << res.second->val <<
    // endl; cin.get();
    root->val = middle->val;
    ListNode* mNext = middle->next;
    prev->next = nullptr;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mNext);
    return root;
}

void start109()
{
    std::array<ListNode, 10> nodes10;
    std::array<ListNode, 9> nodes9;
    std::array<ListNode, 3> nodes3;

    for (size_t i = 0; i < nodes3.size() - 1; ++i)
    {
        nodes3[i] = i;
        nodes3[i].next = &nodes3[i + 1];
    }
    nodes3[nodes3.size() - 1] = nodes3.size() - 1;

    for (size_t i = 0; i < nodes10.size() - 1; ++i)
    {
        nodes10[i] = i;
        nodes10[i].next = &nodes10[i + 1];
    }
    nodes10[nodes10.size() - 1] = nodes10.size() - 1;

    for (size_t i = 0; i < nodes9.size() - 1; ++i)
    {
        nodes9[i] = i;
        nodes9[i].next = &nodes9[i + 1];
    }
    nodes9[nodes9.size() - 1] = nodes9.size() - 1;

    TreeNode* res = sortedListToBST(&nodes10[0]);
    cout << res->val << endl;
    printTree(res, "");

    res = sortedListToBST(&nodes9[0]);
    cout << res->val << endl;
    printTree(res, "");

    res = sortedListToBST(&nodes3[0]);
    cout << res->val << endl;
    printTree(res, "");
}

// lc 637
vector<double> averageOfLevels(TreeNode* root)
{
    vector<double> res;
    if (!root)
        return res;

    queue<TreeNode*> q;
    q.push(root);
    TreeNode* cur;
    double sum;
    int s;

    while (!q.empty())
    {
        s = q.size();
        sum = 0.0;
        for (int i = 0; i < s; i++)
        {
            cur = q.front();
            q.pop();
            sum += cur->val;
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        res.push_back(sum / s);
    }

    return res;
}

// lc 102
vector<vector<int>> levelOrder(TreeNode* root)
{
    if (root == nullptr)
    {
        return {};
    }

    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        size_t size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* cur = q.front();
            q.pop();
            level.push_back(cur->val);
            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
        }
        res.push_back(level);
    }
    return res;
}

void start102()
{
    TreeNode root;
    TreeNode a;
    TreeNode b;
    TreeNode aa;
    TreeNode ab;
    TreeNode bb;
    root.val = 0;
    root.left = &a;
    root.right = &b;
    a.val = 1;
    a.left = &aa;
    a.right = &ab;
    aa.val = 3;
    ab.val = 4;
    b.val = 2;
    b.left = &bb;
    bb.val = 100;

    auto res = levelOrder(&root);
    for (const auto& v : res)
    {
        for (const auto& n : v)
        {
            cout << n << ' ';
        }
        cout << endl;
    }
}

// lc 101
bool isSymmetric(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        size_t size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left != nullptr)
            {
                q.push(cur->left);
                level.push_back(cur->left->val);
            }
            else
            {
                level.push_back(-101); // some val under constraints
            }
            if (cur->right != nullptr)
            {
                q.push(cur->right);
                level.push_back(cur->right->val);
            }
            else
            {
                level.push_back(-101); // some val under constraints
            }
        }
        for (int i = 0; i < level.size() / 2; i++)
        {
            if (level[i] != level[level.size() - 1 - i])
            {
                return false;
            }
        }
    }
    return true;
}

bool step101(TreeNode* node1, TreeNode* node2)
{
    if (node1 == nullptr || node2 == nullptr)
        return node1 == node2;

    if (node1->val != node2->val)
        return false;

    return step101(node1->left, node2->right) && step101(node1->right, node2->left);
}

bool isSymmetricRec(TreeNode* root)
{
    return step101(root->left, root->right);
}

void start101()
{
    TreeNode root;
    TreeNode a;
    TreeNode b;
    TreeNode aa;
    TreeNode ab;
    TreeNode bb;
    TreeNode ba;
    root.val = 0;
    root.left = &a;
    root.right = &b;
    a.val = 1;
    a.left = &aa;
    a.right = &ab;
    aa.val = 2;
    ab.val = 3;
    b.val = 1;
    b.right = &bb;
    b.left = &ba;
    bb.val = 2;
    ba.val = 3;

    cout << isSymmetric(&root) << endl;

    ba.val = 10;
    cout << isSymmetric(&root) << endl;
}

// lc 129
void step129(TreeNode* root, int& sum, int cur)
{
    if (root == nullptr)
    {
        return;
    }

    cur += root->val;
    if (root->left == nullptr && root->right == nullptr)
    {
        cout << sum << "+" << cur << " = " << sum + cur << endl;
        sum += cur;
        return;
    }
    cur *= 10;
    step129(root->left, sum, cur);
    step129(root->right, sum, cur);
    return;
}
int sumNumbers(TreeNode* root)
{
    int sum = 0;
    step129(root, sum, 0);
    return sum;
}

void start129()
{
    TreeNode root;
    TreeNode a;
    TreeNode b;
    TreeNode aa;
    TreeNode ab;
    root.val = 1;
    root.left = &a;
    root.right = &b;
    a.val = 2;
    a.left = &aa;
    a.right = &ab;
    aa.val = 3;
    ab.val = 4;
    b.val = 5;

    cout << sumNumbers(&root) << endl;
}

// TODO:
// https://leetcode.com/problems/insert-into-a-binary-search-tree/
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// https://leetcode.com/problems/flatten-nested-list-iterator/
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

size_t countNodes(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void printTree(TreeNode* root, string prefix)
{
    if (root == nullptr)
    {
        return;
    }
    printTree(root->right, prefix + "r");
    cout << prefix << ':' << root->val << endl;
    printTree(root->left, prefix + "l");
}

int main()
{
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

    // std::cout << "countNodes = " << countNodes(&root) << endl;
    // std::cout << hasPathSum(&root, 3) << endl << hasPathSum(&root, 4) << endl;
    // std::cout << maxDepth(&root) << endl;
    // std::cout << isSameTree(&root, &root) << endl;
    // std::cout << isSameTree(&root, &a) << endl;
    // std::cout << deepestLeavesSum(&root) << endl;
    // std::cout << deepestLeavesSum(&a) << endl;
    // std::cout << deepestLeavesSum(&b) << endl;
    // std::cout << rangeSumBST(&root, 1, 2) << endl;
    // std::cout << rangeSumBST(&root, 3, 4) << endl;
    // std::cout << rangeSumBST(&root, 0, 5) << endl;
    // std::cout << sumEvenGrandparent(&root) << endl;

    // start1038();
    // start700();
    // start98();
    // start94();
    // start876();
    // start109();
    // start102();
    // start101();
    start129();
    return 0;
}
