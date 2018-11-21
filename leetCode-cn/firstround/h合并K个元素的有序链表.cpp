/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
示例:
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(0 == k)
            return nullptr;
        while(k > 1)
        {
            int i = 0;
            while(2 * i + 1 < k)
            {
                lists[i] = merge2Lists(lists[2 * i], lists[2 * i + 1]);
                ++i;
            }
            if(k & 0x1)
            {
                lists[i] = lists[2 * i];
            }
            k = (k + 1) / 2;
        }
        return lists[0];
    }
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode** cur = &l1;
        while(*cur && l2)
        {
            if((*cur)->val > l2->val)
            {
                ListNode* tmp = *cur;
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