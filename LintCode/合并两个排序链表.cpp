/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(NULL == l1 || NULL == l2)
        	return NULL == l2 ? l1 : l2;
        if(l1->val > l2->val)
        	return mergeTwoLists(l2, l1);
        ListNode **pL1 = &l1;
        while(*pL1 && l2) {
        	if((*pL1)->val > l2->val) {
        		ListNode *tmp = l2;
        		l2 = l2->next;
        		tmp->next = *pL1;
        		*pL1 = tmp;
        	}
    		pL1 = &((*pL1)->next);
        }
        if(l2) 
        	*pL1 = l2;
        return l1;
    }
};