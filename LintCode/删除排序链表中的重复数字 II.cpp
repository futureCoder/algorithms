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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
    	if(!head)
    		return head;
        ListNode **cur = &head, **search = &(head->next);
        while(*cur) {
        	if(*search && (*search)->val == (*cur)->val) {
        		while(*search && (*search)->val == (*cur)->val) {
        			ListNode *tmp = *search;
        			*search = (*search)->next;
        			free(tmp);
        		}
    			ListNode *tmp = *cur;
    			*cur = *search;
    			search = &((*cur)->next);
    			free(tmp);
        	}
        	else {
        		cur = search;
        		search = &((*cur)->next);
        	}
        }
        return head;
    }
};