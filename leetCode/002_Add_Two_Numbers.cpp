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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        int cf = 0;
        ListNode *ret = l1, *tmp;
        while(l1 && l2)
        {
        	l1->val += l2->val + cf;
        	cf = l1->val / 10;
        	l1->val %= 10;
        	tmp = l1;
        	l1 = l1->next;
        	l2 = l2->next;
        }
        if(l1 == NULL) tmp->next = l2;
        while(l1 && cf)
        {
        	l1->val += cf;
        	cf = l1->val / 10;
        	l1->val %= 10;
        	tmp = l1;
        	l1 = l1->next;
        }
        while(l2 && cf)
        {
        	l2->val += cf;
        	cf = l2->val / 10;
        	l2->val %= 10;
        	tmp = l2;
        	l2 = l2->next;
        }
        if(cf)
        {
        	tmp->next = (ListNode *)malloc(sizeof(ListNode));
        	tmp = tmp->next;
        	tmp->val = cf;
        	tmp->next = NULL;
        }
        return ret;
    }
};