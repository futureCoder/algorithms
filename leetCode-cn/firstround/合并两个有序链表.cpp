/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode **cur = &l1;
        while(*cur && l2)
        {
            if((*cur)->val > l2->val)
            {
                ListNode *tmp = *cur;
                *cur = l2;
                l2 = tmp;
            }
            cur = &((*cur)->next);
        }
        if(l2)
            *cur = l2;
        return l1;
    }
};