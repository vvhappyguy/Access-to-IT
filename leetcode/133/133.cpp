#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node*> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
    unordered_map<Node*, Node*> nodeMap;

public:
    void dfs(Node* node)
    {
        Node* copy = new Node(node->val);
        nodeMap[node] = copy;
        for (auto ng : node->neighbors)
        {
            if (nodeMap.find(ng) != nodeMap.end())
            {
                copy->neighbors.push_back(nodeMap[ng]);
            }
            else
            {
                dfs(ng);
                copy->neighbors.push_back(nodeMap[ng]);
            }
        }
    }
    Node* cloneGraph(Node* node)
    {
        if (node == nullptr)
            return nullptr;
        dfs(node);
        return mp[node];
    }
};


int main()
{
    Solution s;
    Node a1(1);
    Node a2(2);
    Node a3(3);
    Node a4(4);

    a1.neighbors = {&a2, &a4};
    a2.neighbors = {&a1, &a3};
    a3.neighbors = {&a2, &a4};
    a4.neighbors = {&a1, &a3};

    Node* res = s.cloneGraph(&a1);
    cout << res->val << endl;
    return 0;
}