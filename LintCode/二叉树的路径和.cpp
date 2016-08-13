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
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    void binaryTreePathSum(TreeNode *root, int target, vector<int>& tmp, vector<vector<int>>& ret) {
    	if(NULL == root)
    		return ;
    	if(root->val == target && NULL == root->left && NULL == root->right) {
    		tmp.push_back(root->val);
    		ret.push_back(tmp);
    		tmp.pop_back();
    		return ;
    	}
    	tmp.push_back(root->val);
    	int nextTarget = target - root->val;
    	binaryTreePathSum(root->left, nextTarget, tmp, ret);
    	binaryTreePathSum(root->right, nextTarget, tmp, ret);
    	tmp.pop_back();
    	return ;
    }
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        vector<vector<int>> ret;
        vector<int> tmp;
        binaryTreePathSum(root, target, tmp, ret);
        return ret;
    }
};