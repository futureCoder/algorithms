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
	void pathSum(TreeNode* root, int sum, vector<int> &cur, vector<vector<int>> &ret) {
		if(!root) return ;
		cur.push_back(root->val);
		if(root->val == sum && !root->left && !root->right)
		{
			ret.push_back(cur);
		}
		pathSum(root->left, sum - root->val, cur, ret);
		pathSum(root->right, sum - root->val, cur, ret);
		cur.pop_back();
		return ;
	}
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> cur;
        pathSum(root, sum, cur, ret);
        return ret;
    }
};