/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        ListNode *pre = head, *target = head;
        int len = 1;
        while(k)
        {
            --k;
            target = target->next;
            if(target == NULL) 
            {
                k %= len;
                target = head;
            }
            ++len;
        }
        if(k > 0) return NULL;
        while(target->next)
        {
            target = target->next;
            pre = pre->next;
        }
        target->next = head;
        head = pre->next;
        pre->next = NULL;
        return head;
    }
};