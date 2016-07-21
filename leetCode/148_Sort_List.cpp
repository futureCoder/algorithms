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
	ListNode* mergeLinkList(ListNode* l1, ListNode *l2)
	{
		ListNode **cur = &l1;
		while(*cur && l2)
		{
			if((*cur)->val > l2->val)
			{
				ListNode *tmp = l2->next;
				l2->next = *cur;
				*cur = l2;
				l2 = tmp;
			}
			cur = &((*cur)->next);
		}
		if(l2)
			*cur = l2;
			return l1;
	}
    ListNode* sortList(ListNode* head) {
    	if(!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next)
        {
        	slow = slow->next;
        	fast = fast->next->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        return mergeLinkList(sortList(head),sortList(slow));
    }
};