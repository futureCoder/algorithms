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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    void postOrder(TreeNode *root, vector<int>& ret) {
    	if(!root)
    		return ;
    	postOrder(root->left, ret);
    	postOrder(root->right, ret);
    	ret.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        postOrder(root, ret);
        return ret;
    }
};