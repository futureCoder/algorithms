#ifndef _COMMON__H_
#define _COMMON__H_
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <functional>
#include <future>
using namespace std;
using vecIter = std::vector<int>::iterator;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedList{
public:
    static ListNode *createLinkedList(vecIter beg, vecIter end)
    {
        ListNode *head = (beg == end) ? nullptr : new ListNode(*beg++);
        for(ListNode *cur = head; beg != end; cur = cur->next)
            cur->next = new ListNode(*beg++);
        return head;
    }
    bool static compareTwoLinkedList(ListNode *l1, ListNode *l2)
    {
        for(; l1 && l2; l1 = l1->next, l2 = l2->next)
            if(l1->val != l2->val)
                return false;
        return l1 || l2 ? false : true;
    }
    void static clearLinkedList(ListNode *head)
    {
        while(head)
        {
            ListNode *cur = head;
            head = head->next;
            delete cur;
        }
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


#endif // _COMMON__H_

