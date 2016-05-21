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
	TreeNode* rebuild(vector<int>& preorder,int start, int end, vector<int>& inorder,int start1, int end1)
	{
		TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
		root->left = root->right = NULL;
		root->val = preorder[start];
		int pos = start1;
		while(inorder[pos] != root->val) ++pos;
		root->left = rebuild(preorder,start + 1, start + pos - start1, )
	}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return bulid(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};