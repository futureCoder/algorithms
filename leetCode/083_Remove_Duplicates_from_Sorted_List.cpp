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
    ListNode* deleteDuplicates(ListNode* head) {
    	if(head == NULL) return head;
        ListNode *pre, *tail;
        for(pre = head,tail = head->next;tail;tail = pre->next)
        {
        	if(pre->val == tail->val)
        	{
        		pre->next = tail->next;
        		free(tail);
        	}
        	else pre = pre->next;
        }
        return head;
    }
};