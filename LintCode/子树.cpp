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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if(NULL == T1 && NULL == T2)
            return true;
        if(NULL == T2)
            return true;
        if(NULL == T1)
            return false;
        if(isSametree(T1, T2))
            return true;
        bool left = isSubtree(T1->left, T2);
        if(left)
            return true;
        bool right = isSubtree(T1->right, T2);
        if(right)
            return true;
        return false;
    }
    bool isSametree(TreeNode *T1, TreeNode *T2) {
        if(NULL == T1 && NULL == T2)
            return true;
        if(NULL == T1 || NULL == T2)
            return false;
        if(T1->val != T2->val)
            return false;
        return isSametree(T1->left, T2->left) && isSametree(T1->right, T2->right);
    }
};