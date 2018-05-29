/*
反转一个单链表。
示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        return reverseList_Recursive(head);
    }
    ListNode* reverseList_Iterative(ListNode* head) {
        ListNode *ret = nullptr;
        while(head)
        {
            ListNode *tmp = head->next;
            head->next = ret;
            ret = head;
            head = tmp;
        }
        return ret;
    }
    ListNode* reverseList_Recursive(ListNode* head) {
        return reverseList_Recursive(nullptr, head);
    }
    ListNode* reverseList_Recursive(ListNode* pre, ListNode* curr) {
        ListNode *next = curr->next;
        curr->next = pre;
        if(nullptr == next)
        {
            curr->next = pre;
            return curr;
        }
        return reverseList_Recursive(curr, next);
    }
};