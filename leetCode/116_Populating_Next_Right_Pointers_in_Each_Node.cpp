/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	void connect(TreeLinkNode *root, TreeLinkNode *next) {
		if(!root) return;
		root->next = next;
		connect(root->left,root->right);
		if(root->next)
			connect(root->right,root->next->left);
		else
			connect(root->right,NULL);
		return ;
	}
    void connect(TreeLinkNode *root) {
        connect(root, NULL);
    }
};