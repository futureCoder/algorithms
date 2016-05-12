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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if(m > n) swap(m,n);
    	int one = m - 1, two = n - m;
    	ListNode **pre = &head, **current = &head;
    	while(*pre && one)
    	{
    		pre = &((*pre)->next);
    		--one;
    	}
    	current = &((*pre)->next);
    	while(*current && two)
    	{
    		ListNode *second = (*current)->next;
    		(*current)->next = *pre;
    		*pre = *current;
    		*current = second;
    		--two;
    	}
    	return head;
    }
};