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
     * @param root: The root of binary tree
     * @return root of new tree
     */
    TreeNode* cloneTree(TreeNode *root) {
        if(NULL == root)
        	return NULL;
        TreeNode *cloneRoot = new TreeNode(root->val);
        cloneRoot->left = cloneTree(root->left);
        cloneRoot->right = cloneTree(root->right);
        return cloneRoot;
    }
};