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
    ListNode *detectCycle(ListNode *head) {
        ListNode *one = head, *two = head;
        while(two && two->next)
        {
        	one = one->next;
        	two = two->next->next;
        	if(one == two) break;
        }
        if(two==NULL || two->next == NULL) return NULL;
        two = head;
        while(one != two)
        {
        	one = one->next;
        	two = two->next;
        }
        return one;
    }
};