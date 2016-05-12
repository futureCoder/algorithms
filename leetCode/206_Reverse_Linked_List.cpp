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
    ListNode* reverseList(ListNode* head) {
        ListNode *ret = NULL, *current = head;
        while(current)
        {
        	ListNode *tmp = current->next;
        	current->next = ret;
        	ret = current;
        	current = tmp;
        }
        return ret;
    }
};