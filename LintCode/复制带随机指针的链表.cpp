/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(NULL == head)
            return NULL;
        RandomListNode *cur = head;
        while(cur) {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur = head;
        while(cur) {
            if(cur->random)     //Caution : verify cur->random 
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        cur = head;
        RandomListNode *ret = new RandomListNode(-1);
        RandomListNode *pCopy = ret;
        while(cur) {
            pCopy->next = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            pCopy = pCopy->next;
        }
        pCopy = ret;
        ret = ret->next;
        free(pCopy);
        return ret;
    }
};
