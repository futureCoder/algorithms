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
        stack<ListNode*> sa, sb;
        while(headA) {
        	sa.push(headA);
        	headA = headA->next;
        }
        while(headB) {
        	sb.push(headB);
        	headB = headB->next;
        }
        ListNode *ret = NULL;
        while(!sa.empty() && !sb.empty() && sa.top() == sb.top()) {
        	ret = sa.top();
        	sa.pop();
        	sb.pop();
        }
        return ret;
    }
};