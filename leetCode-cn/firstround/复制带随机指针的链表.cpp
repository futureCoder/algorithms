/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
要求返回这个链表的深度拷贝。 
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
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
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return head;
        constructRandomList(head);
        return detachRandomList(head);
    }

    void constructRandomList(RandomListNode *head)
    {
        while(head)
        {
            RandomListNode *newNode = new RandomListNode(head->label);
            newNode->next = head->next;
            head->next = newNode;
            head = newNode->next;
        }
    }

    RandomListNode *detachRandomList(RandomListNode *head)
    {
        RandomListNode *ret = head->next;
        while(head)
        {
            RandomListNode *cur = head->next;
            RandomListNode *nextHead = cur->next;
            cur->next = nextHead ? nextHead->next : nullptr;
            cur->random = head->random ? head->random->next : nullptr;
            head->next = nextHead;
            head = nextHead;
        }
        return ret;
    }
};