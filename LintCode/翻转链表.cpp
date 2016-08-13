/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
    	if(NULL == head)
    		return head;
        ListNode *prev = head->next;
        head->next = NULL;
        while(NULL != prev) {
            ListNode *tmp = prev->next;
            prev->next = head;
            head = prev;
            prev = tmp;
        }
        return head;
    }
};
