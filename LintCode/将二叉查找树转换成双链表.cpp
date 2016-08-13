/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        typedef pair<TreeNode*, bool> node;
        stack<node> s;
        DoublyListNode *head = new DoublyListNode(-1);
        DoublyListNode *tail = head;
        if(root)
        	s.push(make_pair(root, false));
        while(!s.empty()) {
        	TreeNode *cur = s.top().first;
        	bool visited = s.top().second;
        	s.pop();
        	if(visited) {
        		DoublyListNode *tmp = new DoublyListNode(cur->val);
        		tail->next = tmp;
        		tmp->prev = tail;
        		tail = tmp;
        	}
        	else {
        		if(cur->right)
        			s.push(make_pair(cur->right, false));
        		s.push(make_pair(cur, true));
        		if(cur->left)
        			s.push(make_pair(cur->left, false));
        	}
        }
        DoublyListNode *toFree = head;
        head = head->next;
        if(head)
        	head->prev = NULL;
        free(toFree);
        return head;
    }
};


