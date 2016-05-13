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
    ListNode* swapPairs(ListNode* head) {
    	if(head == NULL) return head;
        ListNode **one = &head, **two = &head->next;
        while(*one && *two)
        {
        	ListNode *tmp = (*two)->next;
        	(*two)->next = *one;
        	*one = *two;
        	*two = tmp;
        	one = two;
        	two = &((*two)->next);
        }
        return head;
    }
};