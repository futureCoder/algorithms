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
    bool isValidBST(TreeNode* root) {
    	if(!root) return true;
        TreeNode *left = root->left,*right = root->right;
        if(left && root->val <= left->val) return false;
        if(right && root->val >= right->val) return false;
        while(left && left->right) left = left->right;
        if(left && root->val <= left->val) return false;
        while(right && right->left) right = right->left;
        if(right && root->val >= right->val) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};