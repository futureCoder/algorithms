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
    ListNode* partition(ListNode* head, int x) {
        ListNode **current = &head,**search = &head;
        while(*search)
        {
        	if((*search)->val < x)
        	{
        		if(current == search)
        		{
        			current = &((*current)->next);
        			search = &((*search)->next);
        			continue;
        		}
        		ListNode *tmp = *search;
        		*search = (*search)->next;
        		tmp->next = *current;
        		*current = tmp;
        		current = &((*current)->next);
        	}
        	else
        		search = &((*search)->next);
        }
        return head;
    }
};