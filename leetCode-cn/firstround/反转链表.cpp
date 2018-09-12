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
        return reverseList_Recusive(head);
    }
    ListNode* reverseList_Recusive(ListNode* head) {
        return reverseList_Recusive(nullptr, head);
    }

    ListNode* reverseList_Recusive(ListNode* pre, ListNode* cur) {
        if(nullptr == cur)
            return pre;
        ListNode* next = cur->next;
        cur->next = pre;
        return reverseList_Recusive(cur, next);
    }

    ListNode* reverseList_Iterative_HeadInsert(ListNode* head) {
        ListNode* ret = nullptr;
        while(nullptr != head)
        {
            ListNode* next = head->next;
            head->next = ret;
            ret = head;
            head = next;
        }
        return ret;
    }
};