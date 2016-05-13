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
	ListNode** reverseLinkList(ListNode **start,ListNode **end)
	{
		//if(*start == NULL) return NULL;
		ListNode *cur = *start, *stub = *start, *reserve = *end;
		while(cur != reserve)
		{
			ListNode *tmp = cur->next;
			cur->next = *start;
			*start = cur;
			cur = tmp;
		}
		stub->next = reserve;
		return &(stub->next);
	}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode **start = &head,**end = &head;
        int i;
        while(1)
        {
	        for(i = 0; i < k && *end; ++i)
	        	end = &((*end)->next);
	        if(i != k)
	        	break;
	        start = reverseLinkList(start,end);
	        end = start;
    	}
    	return head;
    }
};