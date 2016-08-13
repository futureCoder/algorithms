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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int start1, int end1, int start2, int end2) {
        if(start1 >= end1 || start2 >= end2)
            return NULL;
        int idx = start2;
        while(idx < end2 && preorder[start1] != inorder[idx])
            ++idx;
        TreeNode *root = new TreeNode(inorder[idx]);
        root->left = buildTree(preorder, inorder, start1 + 1, start1 + 1 + idx - start2, start2, idx);
        root->right = buildTree(preorder, inorder, start1 + 1 + idx - start2, end1, idx + 1, end2);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};