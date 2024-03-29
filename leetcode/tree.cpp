#include <algorithm>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
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

// lc 958
bool isCompleteTree(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    while (q.front() != nullptr)
    {
        TreeNode* cur = q.front();
        q.pop();

        q.push(cur->left);
        q.push(cur->right);
    }

    while (!q.empty() && q.front() == nullptr)
    {
        q.pop();
    }

    return q.empty();
}

void start958()
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

    cout << isCompleteTree(&root) << endl;
    a.left = nullptr;
    cout << isCompleteTree(&root) << endl;
    a.left = &aa;
    a.right = nullptr;
    b.left = &ab;
    cout << isCompleteTree(&root) << endl;
}

// lc 108
TreeNode* step108(vector<int>& nums, size_t startIndex, size_t endIndex)
{
    if (startIndex == endIndex)
    {
        return new TreeNode(nums[startIndex]);
    }

    size_t middleIndex = startIndex + (endIndex - startIndex) / 2;
    cout << startIndex << ':' << endIndex << '=' << middleIndex << endl;
    cin.get();
    TreeNode* node = new TreeNode(nums[middleIndex]);

    if (middleIndex != startIndex)
        node->left = step108(nums, startIndex, middleIndex - 1);
    if (middleIndex != endIndex)
        node->right = step108(nums, middleIndex + 1, endIndex);

    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    return step108(nums, 0, nums.size() - 1);
}

void start108()
{
    std::vector<int> nodes1 = {0};
    TreeNode* res = sortedArrayToBST(nodes1);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;

    std::vector<int> nodes2 = {0, 1};
    res = sortedArrayToBST(nodes2);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;

    std::vector<int> nodes3 = {0, 1, 2};
    res = sortedArrayToBST(nodes3);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;

    std::vector<int> nodes6 = {0, 1, 2, 3, 4, 5};
    res = sortedArrayToBST(nodes6);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;

    std::vector<int> nodes10 = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4};
    res = sortedArrayToBST(nodes10);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;

    std::vector<int> nodes9 = {-4, -3, -2, -1, 0, 1, 2, 3, 4};
    res = sortedArrayToBST(nodes9);
    cout << res->val << endl;
    printTree(res, "");
}

// lc 106
TreeNode* step106(vector<int>& inorder, size_t iB, size_t iE, vector<int>& postorder, size_t pB, size_t pE)
{
    if (iB >= iE || pB >= pE)
    {
        return nullptr;
    }

    int val = postorder[pE - 1];
    TreeNode* node = new TreeNode(val);

    auto it = std::find(begin(inorder) + iB, begin(inorder) + iE, val);
    size_t diff = it - begin(inorder) - iB;
    node->left = step106(inorder, iB, iB + diff, postorder, pB, pB + diff);
    node->right = step106(inorder, iB + diff + 1, iE, postorder, pB + diff, pE - 1);

    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    size_t size = postorder.size();
    if (size == 0)
    {
        return nullptr;
    }

    return step106(inorder, 0, size, postorder, 0, size);
}

TreeNode* step106Improve(std::map<int, size_t>& indexes,
                         vector<int>& inorder,
                         size_t iB,
                         size_t iE,
                         vector<int>& postorder,
                         size_t pB,
                         size_t pE)
{
    if (iB >= iE || pB >= pE)
    {
        return nullptr;
    }

    int val = postorder[pE - 1];
    TreeNode* node = new TreeNode(val);

    auto it = indexes.at(val);
    size_t diff = it - iB;
    node->left = step106Improve(indexes, inorder, iB, iB + diff, postorder, pB, pB + diff);
    node->right = step106Improve(indexes, inorder, iB + diff + 1, iE, postorder, pB + diff, pE - 1);

    return node;
}

TreeNode* buildTreeImprove(vector<int>& inorder, vector<int>& postorder)
{
    size_t size = postorder.size();
    if (size == 0)
    {
        return nullptr;
    }
    std::map<int, size_t> indexes;
    for (int i = 0; i < inorder.size(); i++)
    {
        indexes.insert({inorder[i], i});
    }

    return step106Improve(indexes, inorder, 0, size, postorder, 0, size);
}

void start106()
{
    vector<int> io = {1};
    vector<int> po = {1};
    TreeNode* res = buildTree(io, po);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;

    io = {9, 3, 15, 20, 7};
    po = {9, 15, 7, 20, 3};
    res = buildTree(io, po);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;

    io = {2};
    po = {2};
    res = buildTree(io, po);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;
}

void start106Improve()
{
    vector<int> io = {1};
    vector<int> po = {1};
    TreeNode* res = buildTreeImprove(io, po);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;

    io = {9, 3, 15, 20, 7};
    po = {9, 15, 7, 20, 3};
    res = buildTreeImprove(io, po);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;

    io = {2};
    po = {2};
    res = buildTreeImprove(io, po);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;
}

// lc 105. Construct Binary Tree from Preorder and Inorder Traversal
TreeNode* step105(std::map<int, int>& indexes,
                  vector<int>& inorder,
                  size_t iB,
                  size_t iE,
                  vector<int>& preorder,
                  size_t pB,
                  size_t pE)
{
    if (iB > iE || pB > pE)
    {
        return nullptr;
    }

    int val = preorder[pB];
    TreeNode* node = new TreeNode(val);

    auto it = indexes.at(val);
    size_t diff = it - iB;
    cout << "diff=" << diff << endl << "i=" << iB << ":" << iE << endl << "p=" << pB << ":" << pE << endl;
    cin.get();
    node->left = step105(indexes, inorder, iB, it - 1, preorder, pB + 1, pB + diff);
    node->right = step105(indexes, inorder, it + 1, iE, preorder, pB + diff + 1, pE);

    return node;
}

TreeNode* buildTreePrIn(vector<int>& preorder, vector<int>& inorder)
{
    size_t size = preorder.size();
    if (size == 0)
    {
        return nullptr;
    }
    std::map<int, int> indexes;
    for (int i = 0; i < preorder.size(); i++)
    {
        indexes.insert({inorder[i], i});
    }

    return step105(indexes, inorder, 0, size - 1, preorder, 0, size - 1);
}

void start105()
{
    vector<int> io = {1};
    vector<int> po = {1};
    TreeNode* res = buildTreePrIn(io, po);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;

    io = {9, 3, 15, 20, 7};
    po = {3, 9, 20, 15, 7};
    res = buildTreePrIn(io, po);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;

    io = {2};
    po = {2};
    res = buildTreePrIn(io, po);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;
}

// lc 111
void step111(TreeNode* root, int& min, int a)
{
    if (root == nullptr)
    {
        return;
    }
    if (a > min)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        min = a;
        return;
    }
    step111(root->left, min, a + 1);
    step111(root->right, min, a + 1);
    return;
}

int minDepth(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    int min = 100001;
    step111(root, min, 1);
    return min;
}

void start111()
{
    TreeNode root;
    TreeNode a;
    TreeNode b;
    TreeNode aa;
    TreeNode ab;
    root.val = 4;
    root.left = &a;
    root.right = &b;
    a.val = 1;
    a.left = &aa;
    a.right = &ab;
    aa.val = 0;
    ab.val = 2;
    b.val = 5;

    cout << minDepth(&root) << endl;
}

// lc 701
TreeNode* insertIntoBST(TreeNode* root, int val)
{
    if (root == nullptr)
    {
        return new TreeNode(val);
    }
    if (root->val > val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

void start701()
{
    TreeNode root;
    TreeNode a;
    TreeNode b;
    TreeNode aa;
    TreeNode ab;
    root.val = 4;
    root.left = &a;
    root.right = &b;
    a.val = 1;
    a.left = &aa;
    a.right = &ab;
    aa.val = 0;
    ab.val = 2;
    b.val = 5;

    TreeNode* res = insertIntoBST(&root, -1);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;

    res = insertIntoBST(&root, 10);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;

    res = insertIntoBST(&root, 3);
    cout << res->val << endl;
    printTree(res, "");
    cout << "-----------" << endl;
}

// TODO:
// https://leetcode.com/problems/flatten-nested-list-iterator/
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

// lc 208. Implement Trie (Prefix Tree)
class Trie
{
    static constexpr size_t alphabetSize = 28;
    struct TrieNode;
    struct TrieNode
    {
        TrieNode* nodes[alphabetSize];
        bool isEndOfWord;
    };
    TrieNode* root;

    inline constexpr int toIndex(char letter)
    {
        return letter - 'a';
    }

public:
    Trie()
    {
        root = new TrieNode();
        root->isEndOfWord = true;
    }

    void insert(string word)
    {
        TrieNode* cur = root;
        for (const auto& w : word)
        {

            cur->nodes[toIndex(w)] = new TrieNode();
            cur->nodes[toIndex(w)]->isEndOfWord = false;
            cur = cur->nodes[toIndex(w)];
        }
        cur->isEndOfWord = true;
    }

    bool search(string word)
    {
        TrieNode* cur = root;
        for (const auto& w : word)
        {
            if (cur->nodes[toIndex(w)] == nullptr)
            {
                return false;
            }
            cur = cur->nodes[toIndex(w)];
        }
        return cur->isEndOfWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode* cur = root;
        for (const auto& w : prefix)
        {
            if (cur->nodes[toIndex(w)] == nullptr)
            {
                return false;
            }
            cur = cur->nodes[toIndex(w)];
        }
        return true;
    }
};

// lc 297
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (root == nullptr)
        {
            return "";
        }
        string res("");

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == NULL)
            {
                res.append("N,");
            }
            else
            {
                res.append(to_string(curr->val) + ',');
            }
            if (curr != NULL)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        // cout << "data=" << data << endl;
        if (data.size() == 0)
        {
            return nullptr;
        }
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        // cout << ss.eof() << endl;
        while (!q.empty() && !ss.eof())
        {
            TreeNode* curr = q.front();
            q.pop();

            getline(ss, str, ',');
            // cout << str << endl;
            // cin.get();
            if (str == "N")
            {
                curr->left = nullptr;
            }
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                curr->left = leftNode;
                q.push(leftNode);
            }

            getline(ss, str, ',');
            // cout << str << endl;
            // cin.get();
            if (str == "N")
            {
                curr->right = nullptr;
            }
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                curr->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

void start297()
{
    Codec codec;
    string res;
    TreeNode* resTree;

    res = codec.serialize(nullptr);
    cout << res << endl;
    resTree = codec.deserialize(res);
    printTree(resTree, "");

    TreeNode root(10);
    res = codec.serialize(&root);
    cout << res << endl;
    resTree = codec.deserialize(res);
    printTree(resTree, "");

    TreeNode a(1);
    root.left = &a;
    res = codec.serialize(&root);
    cout << res << endl;
    resTree = codec.deserialize(res);
    printTree(resTree, "");

    TreeNode b(2);
    root.right = &b;
    res = codec.serialize(&root);
    cout << res << endl;
    resTree = codec.deserialize(res);
    printTree(resTree, "");

    root.left = nullptr;
    res = codec.serialize(&root);
    cout << res << endl;
    resTree = codec.deserialize(res);
    printTree(resTree, "");

    root.left = &a;
    TreeNode aa(8);
    TreeNode ab(9);
    a.left = &aa;
    a.right = &ab;
    res = codec.serialize(&root);
    cout << res << endl;
    resTree = codec.deserialize(res);
    printTree(resTree, "");

    // root.val = 4;
    // root.left = &a;
    // root.right = &b;
    // a.val = 1;
    // a.left = &aa;
    // a.right = &ab;
    // aa.val = 0;
    // ab.val = 2;
    // b.val = 5;
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
    // start129();
    // start958();
    // start108();
    // start106();
    // start106Improve();
    // start701();
    // start105();
    // start297();
    // start111();
    start1372();
    return 0;
}
