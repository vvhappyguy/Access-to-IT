// https://leetcode.com/problems/add-two-numbers/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

}

int getSize(ListNode _head)
{
    int res = 1;
    while(_head.next)
    {
        res++;
        _head = *(_head.next);
    }
    return res;
}

void printListNode(ListNode _head)
{
    while(&_head)
    {
        printf("%p=%d\n", &_head, _head.val);
        if(_head.next)
        {
            _head = *(_head.next);
        }
        else
        {
            break;
        }
    }
}

int main(int args, char* argv[]){
    printf("Setup\n");
    ListNode a3 = {3};
    ListNode a2 = {4};
    ListNode a1 = {2};
    a3.next = 0;
    a2.next = &a3;
    a1.next = &a2;

    ListNode b3 = {4};
    ListNode b2 = {6};
    ListNode b1 = {5};
    b3.next = 0;
    b2.next = &b3;
    b1.next = &b2;

    printf("Print\nb1\n");
    printListNode(b1);
    printf("a1\n");
    printListNode(a1);

    ListNode* result, *curr = malloc(sizeof(ListNode));
    ListNode *currB = &b1, *currA = &a1;
    int bit = 0;
    printf("Start");
    while(currB || currA)
    {
        curr->val = (currA->val + currB->val + bit) % 10;
        printf("%d", curr->val);
        bit = (currA->val + currB->val) / 10;
        if(bit || currA->next || currB->next)
        {
            curr->next = malloc(sizeof(ListNode));
            curr = curr->next;
            if(currA->next != 0)
            {
                currA = currA->next;
            }
            else
            {
                currA = 0;
            }
            if(currB->next != 0)
            {
                currB = currB->next;
            }
            else
            {
                currB = 0;
            }
        }

    }
    printListNode(*result);

    return 0;
}