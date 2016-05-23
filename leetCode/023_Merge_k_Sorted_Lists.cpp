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
	ListNode* mergeLists(ListNode *l1,ListNode *l2) {
		ListNode **cur = &l1;
		while(*cur && l2)
		{
			ListNode *tmp;
			if((*cur)->val >= l2->val)
			{
				tmp = l2->next;
				l2->next = *cur;
				*cur = l2;
				l2 = tmp;
			}
			cur = &((*cur)->next);
		}
		if(l2) *cur = l2;
		return l1;
	}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(!k) return NULL;
        while(k > 1){
        	for(int i = 0;i < k/2;++i)
        	{
        		lists[i] = mergeLists(lists[i],lists[k - 1 - i]);
        	}
        	k = (k + 1) / 2;
        }
        return lists[0];
    }
};