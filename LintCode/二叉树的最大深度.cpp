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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        return postOrder(root);
    }
    int postOrder(TreeNode *root) {
    	if(NULL == root)
    		return 0;
    	int ret = max(postOrder(root->left), postOrder(root->right));
    	return ret + 1;
    }
};