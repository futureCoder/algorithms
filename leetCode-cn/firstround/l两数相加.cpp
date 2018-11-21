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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(nullptr == l1)
            return l2;
        if(nullptr == l2)
            return l1;
        ListNode** ret = &l1;
        int cf = 0;
        while(*ret && l2)
        {
            (*ret)->val += l2->val + cf;
            cf = (*ret)->val / 10;
            (*ret)->val %= 10;
            ret = &((*ret)->next);
            l2 = l2->next;
        }
        if(l2)
        {
            //慎用,会改变l1结构,将l1、l2变为带有公共区域的链表
            *ret = l2;
        }
        while(*ret && cf)
        {
            (*ret)->val += cf;
            cf = (*ret)->val / 10;
            (*ret)->val %= 10;
            ret = &((*ret)->next);
        }
        if(cf)  //使用while,来增强异常安全性
        {
            ListNode* newNode = new ListNode(cf);
            *ret = newNode; 
        }
        return l1;
    }
};