/**
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

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
        if(nullptr == l1)
            return l2;
        if(nullptr == l2)
            return l1;
        ListNode *ret = l1, *pre1;
        ListNode *pre2;     //防止函数返回后，析构 l2 时出问题
        int cf = 0;
        while(l1 && l2)
        {
            l1->val += l2->val + cf;
            cf = l1->val / 10;
            l1->val %= 10;
            pre1 = l1;
            pre2 = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(nullptr == l1)
        {
            pre1->next = l2;
            pre2->next = nullptr;   //pre2的作用到此为止
            l1 = l2;
        }
        while(l1 && cf)
        {
            l1->val += cf;
            cf = l1->val / 10;
            l1->val %= 10;
            pre1 = l1;
            l1 = l1->next;
        }
        if(cf)
        {
            ListNode* newNode = new ListNode(cf);
            pre1->next = newNode;
        }
        return ret;
    }
};