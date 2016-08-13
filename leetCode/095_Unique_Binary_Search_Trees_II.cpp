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
	vector<TreeNode*> generateTrees(int start, int end) {
		vector<TreeNode*> ret;
		if(start > end) {
			ret.push_back(NULL);
			return ret;
		}
		for(int i = start; i <= end; ++i) {
			vector<TreeNode*> vecLeft(generateTrees(start, i - 1));
			vector<TreeNode*> vecRight(generateTrees(i + 1, end));
			for(int l = 0; l < vecLeft.size(); ++l)
				for(int r = 0; r < vecRight.size(); ++r) {
					TreeNode *root = new TreeNode(i);
					root->left = vecLeft[l];
					root->right = vecRight[r];
					ret.push_back(root);
				}
		}
		return ret;
	}
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
        	return vector<TreeNode*>(NULL);
        return generateTrees(1, n);
    }
};