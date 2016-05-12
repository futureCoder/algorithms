class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {	//递归版
		if (!head || !head->next) return head;
		ListNode *p = head->next;
		if (head->val == p->val) 
		{
			while (p && head->val == p->val) 
			{
				ListNode *tmp = p;
				p = p->next;
				delete tmp;
			}
			delete head;
			return deleteDuplicates(p);
		} 
		else 
		{
			head->next = deleteDuplicates(head->next);
			return head;
		}
	}
};