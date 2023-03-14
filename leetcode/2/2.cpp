
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* result = new ListNode();
    ListNode* res = result;
    int flag = 0;
    int val = 0;

    do
    {
        val = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + flag;
        result->val = val % 10;
        flag = val / 10;
        l1 = (l1 != nullptr ? l1->next : nullptr);
        l2 = (l2 != nullptr ? l2->next : nullptr);
        if (l1 != nullptr || l2 != nullptr)
        {
            result->next = new ListNode();
            result = result->next;
        }
    } while (l1 != nullptr || l2 != nullptr);
    if (flag != 0)
    {
        result->next = new ListNode(1);
        result = result->next;
    }

    return res;
}