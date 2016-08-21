/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head)
            return head;
        ListNode **tarStart = &head;
        int i = 0;
        while(*tarStart && ++i < m)
            tarStart = &((*tarStart)->next);
        ListNode **tarCurr = &((*tarStart)->next);
        while(*tarCurr && ++i <= n) {
            ListNode *Second = (*tarCurr)->next;
            (*tarCurr)->next = *tarStart;
            *tarStart = *tarCurr;
            *tarCurr = Second;
        }
        return head;
    }
};
