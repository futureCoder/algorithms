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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int left, right;
        left = minDepth(root->left);
        right = minDepth(root->right);
        if((!left || !right) && (left || right)) return (left == 0 ? right : left) + 1;
        return min(left,right) + 1;
    }
};