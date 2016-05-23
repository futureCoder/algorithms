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
	void sumNumbers(TreeNode* root, int cur, int &ret) {
		cur = cur * 10 + root->val;
		if(!root->left && !root->right)
		{
			ret += cur;
			return ;
		}
		if(root->left) sumNumbers(root->left, cur, ret);
		if(root->right) sumNumbers(root->right, cur, ret);
		return ;
	}
    int sumNumbers(TreeNode* root) {
        int ret = 0, weight = 1;
        if(root) sumNumbers(root, 0, ret);
        return ret;
    }
};