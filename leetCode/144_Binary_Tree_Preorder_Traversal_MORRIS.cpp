class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		TreeNode *cur = root, *prev = nullptr;
		while (cur != nullptr)
		{
			if (cur->left == nullptr)
			{
				result.push_back(cur->val);
				prev = cur;
				cur = cur->right;
			}
			else
			{
				TreeNode *node = cur->left;
				while (node->right != nullptr && node->right != cur)
					node = node->right;
				if (node->right == nullptr)
				{
					result.push_back(cur->val);
					node->right = cur;
					prev = cur;
					cur = cur->left;
				}
				else
				{
					node->right = nullptr;
					cur = cur->right;
				}
			}
		}
		return result;
	}
};