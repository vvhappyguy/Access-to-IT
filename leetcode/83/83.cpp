#include <iostream>
#include <array>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == nullptr)
        {
            return head;
        }

        ListNode* prev = head;
        ListNode* cur = prev->next;

        while (cur != nullptr)
        {
            if (cur->val == prev->val)
            {
                prev->next = cur->next;
                cur = cur->next;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

void printListNode(ListNode* head)
{
    while (head != nullptr)
    {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution s;
    std::array<ListNode, 10> nodes10;

    for (size_t i = 0; i < nodes10.size() - 1; ++i)
    {
        nodes10[i] = i / 2;
        nodes10[i].next = &nodes10[i + 1];
    }
    nodes10[nodes10.size() - 1] = nodes10.size() - 1;

    printListNode(&nodes10[0]);
    s.deleteDuplicates(&nodes10[0]);
    printListNode(&nodes10[0]);

    return 0;
}