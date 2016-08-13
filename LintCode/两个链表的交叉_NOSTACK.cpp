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
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	int la = 0, lb = 0;
        ListNode *pA = headA, *pB = headB;
        while(pA) {
        	++la;
        	pA = pA->next;
        }
        while(pB) {
        	++lb;
        	pB = pB->next;
        }
        pA = headA, pB = headB;
        while(la > lb) {
        	--la;
        	pA = pA->next;
        }
        while(lb > la) {
        	--lb;
        	pB = pB->next;
        }
        while(pA != pB) {
        	pA = pA->next;
        	pB = pB->next;
        }
        return pA;
    }
};