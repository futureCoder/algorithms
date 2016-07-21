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
	TreeNode* build(vector<int> nums, int start, int end) {
		if(start == end)
			return NULL;
		int mid = start + (end - start) / 2;
		TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
		root->val = nums[mid];
		root->left = build(nums, start, mid);
		root->right = build(nums, mid + 1, end);
		return root;
	}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
};