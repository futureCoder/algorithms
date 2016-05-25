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
 	ListNode* insertionSortList(ListNode* head) {
 		ListNode **search = &head;
 		if(!*search) return head;
 		ListNode **cur = &head->next;
 		while(*cur)
 		{
 			ListNode *tmp = *cur;
 			while(*search != *cur && (*search)->val < (*cur)->val) search = &((*search)->next);
 			if(*search != *cur)
 			{
 				*cur = tmp->next;
 				tmp->next = *search;
 				*search = tmp;
 			}
 			else cur = &((*cur)->next);
 			search = &head;
 		}
 		return head;
 	}
 };