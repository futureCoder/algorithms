/*
环形链表
给定一个链表，判断链表中是否有环。
进阶：
你能否不使用额外空间解决此题？
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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast)
            {
                fast = fast->next;
                if(slow == fast)
                    return true;
            }
        }
        return false;
    }
};