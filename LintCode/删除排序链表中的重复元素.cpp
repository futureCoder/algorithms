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
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
    	if(NULL == head)
    		return head;
        ListNode *cur = head, *search = head->next;
        int val = cur->val;
        while(search) {
        	if(val == search->val) {
        		ListNode *tmp = search;
        		cur->next = search = search->next;
        		free(tmp);
        	}
        	else {
        		cur->next = search;
        		cur = search;
        		val = cur->val;
        		search = search->next;
        	}
        }
        return head;
    }
};