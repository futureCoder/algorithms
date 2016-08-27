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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int instart, int inend, int poststart, int postend) {
    	if(instart > inend || poststart > postend)
    		return NULL;
    	TreeNode *root = new TreeNode(postorder[postend]);
    	int idx = instart;
    	while(inorder[idx] != postorder[postend])
    		++idx;
    	root->left = buildTree(inorder, postorder, instart, idx - 1, poststart, poststart + (idx - 1 - instart));
    	root->right = buildTree(inorder, postorder, idx + 1, inend, poststart + idx - instart, postend - 1);
    	return root;
    }
};