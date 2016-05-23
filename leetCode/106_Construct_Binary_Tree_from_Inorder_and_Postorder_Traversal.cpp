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
	TreeNode* build(vector<int>& inorder, int start, int end, vector<int>& postorder, int start1, int end1){
		if(start > end || start1 > end1) return NULL;
		TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
		root->val = postorder[end1];
		int pos = start;
		while(inorder[pos] != root->val) ++pos;
		root->left = build(inorder, start, pos - 1, postorder, start1, start1 + pos - start - 1);
		root->right = build(inorder, pos + 1, end, postorder, start1 + pos - start, end1 - 1);
		return root;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1); 
    }
};
