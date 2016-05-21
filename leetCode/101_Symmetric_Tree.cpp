/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool symmetric(TreeNode* l, TreeNode* r) {
		if(!l && !r) return true;
		if(!l || !r) return false;
		return l->val == r->val && symmetric(l->left, r->right) && symmetric(l->right, r->left);
	}
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return symmetric(root->left,root->right);
    }
};