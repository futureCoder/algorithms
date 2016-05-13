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
    void reorderList(ListNode* head) {
        if(head == NULL) return ;
        int len = 0;
        ListNode *one = head, *two = head, *tmp;
        while(two && two->next)
        {
        	one = one->next;
        	two = two->next->next;
        }
        two = one->next;
        one->next = NULL;
        one = head;
        ListNode *cur = two;
        two = NULL;
        while(cur)
        {
        	tmp = cur->next;
        	cur->next = two;
        	two = cur;
        	cur = tmp;
        }
        while(one && two)
        {
        	tmp = one->next;
        	one->next = two;
        	two = two->next;
        	one->next->next = tmp;
        	one = one->next->next;
        }
        return ;
    }
};