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
        bool flag = 0;
        ListNode **pre, *cur;
        for(pre = &head,cur = head->next;cur;)
        {
        	if((*pre)->val == cur->val)
        	{
        		ListNode *tmp = cur;
        		cur = cur->next;
        		(*pre)->next = cur;
        		free(tmp);
        		if(flag == 0) flag = 1;
        	}
        	else
        	{
        		if(flag == 1)
        		{
        			ListNode *tmp = *pre;
        			*pre = cur;
        			cur = cur->next;
        			free(tmp);
        			flag = 0;
        		}
        		else
        		{
        			pre = &((*pre)->next);
        			cur = (*pre)->next;
        		}
        	}
        }
        if(flag == 1)
        {
        	ListNode *tmp = *pre;
        	*pre = NULL;
        	free(tmp);
        }
        return head;
    }
};