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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode **pre = &head, **tail = &head;
        while(n--)
        {
        	tail = &((*tail)->next);
        }
        while(*tail)
        {
        	tail = &((*tail)->next);
        	pre = &((*pre)->next);
        }
        ListNode *tmp = *pre;
        *pre = tmp->next;
        free(tmp);
        return head;
    }
};