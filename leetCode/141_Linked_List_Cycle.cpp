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
    bool hasCycle(ListNode *head) {
        ListNode *one = head, *two = head;
        while(two)
        {
        	one = one->next;
        	two = two->next;
        	if(two) two = two->next;
        	else return false;
        	if(two == one) return true;
        }
        return false;
    }
};