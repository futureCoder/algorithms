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
    void handle(TreeNode* root) {
        if(root == NULL) return;
        handle(root->left);
        TreeNode *lLeft = root,*save = root->right;
        while(lLeft->left!=NULL) lLeft = lLeft->left;
        lLeft->left = save;
        root->right = NULL;
        handle(save);
        return ;
    }
    void reverse(TreeNode* root){
        if(root == NULL) return;
        reverse(root->left);
        reverse(root->right);
        swap(root->left,root->right);
        return ;
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        handle(root);
        reverse(root);
        return ;
    }
};