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
		if(start > end || start1 > end1) return NULL;
		TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
		root->val = preorder[start];
		int pos = start1;
		while(inorder[pos] != root->val) ++pos;
		root->left = rebuild(preorder,start + 1, start + pos - start1, inorder, start1, pos - 1);
		root->right = rebuild(preorder, start + pos - start1 + 1, end, inorder, pos + 1, end1);
		return root;
	}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return rebuild(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};