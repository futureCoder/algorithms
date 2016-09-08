/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class IdenticalTree {
public:
    bool chkIdentical(TreeNode* A, TreeNode* B) {
        if(isSameStruct(A, B))
            return true;
        if(chkIdentical(A->left, B))
            return true;
        if(chkIdentical(A->right, B))
            return true;
        return false;
    }
private:
    bool isSameStruct(TreeNode* a, TreeNode* b) {
        if(NULL == a && NULL == b)
            return true;
        if(NULL == a || NULL == b)
            return false;
        return a->val == b->val && isSameStruct(a->left, b->left) && isSameStruct(a->right, b->right);
    }
};