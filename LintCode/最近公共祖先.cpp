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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        TreeNode *left = NULL, *right = NULL;
        if(NULL == root)
        	return NULL;
        left = lowestCommonAncestor(root->left, A, B);
        right = lowestCommonAncestor(root->right, A, B);
        if(NULL != left && NULL != right)
        	return root;
    	if(root == A || root == B)
    		return root;
        if(left || right)
        	return NULL != left ? left : right;
        return NULL;
    }
};