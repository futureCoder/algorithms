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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(n < 1)
            n = 1;
        int k = 0;
        ListNode **tail = &head;
        while(*tail && k != n) {
            tail = &((*tail)->next);
            ++k;
        }
        if(k != n)
            return head;
        ListNode **target = &head;
        while(*tail) {
            tail = &((*tail)->next);
            target = &((*target)->next);
        }
        ListNode *tmp = *target;
        *target = tmp->next;
        free(tmp);
        return head;
    }
};


