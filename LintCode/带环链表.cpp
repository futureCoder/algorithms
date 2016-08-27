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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
    	if(NULL == head)
    		return false;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
        	if(slow == fast)
        		return true;
        	slow = slow->next;
        	fast = fast->next->next;
        }
        return false;
    }
};


