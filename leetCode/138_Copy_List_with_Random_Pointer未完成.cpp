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
	void initLinkList(RandomListNode *head,RandomListNode *ret,unordered_map<RandomListNode *,RandomListNode *> &mymap)
	{
		while(head)
		{
			RandomListNode *tmp = (RandomListNode *)malloc(sizeof(RandomListNode));
			tmp->label = head->label;
			tmp->next = NULL;
			tmp->random = NULL;
			mymap[head] = tmp;
			ret->next = tmp;
			ret = ret->next;
		}
	}
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *,RandomListNode *> mymap;
        mymap[0] = 0;
        RandomListNode *ret = (RandomListNode*)malloc(sizeof(RandomListNode));
        ret->next = NULL;
        ret->random = NULL;
        initLinkList(head,ret,mymap);
        RandomListNode *start = ret->next;
        while(head)
        {
        	start->random = mymap[head->random];
        	head = head->next;
        	start = start->next;
        }
        return ret->next;
    }
};