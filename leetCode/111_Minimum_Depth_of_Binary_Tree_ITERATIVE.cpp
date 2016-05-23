class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int result = INT_MAX;
		stack<pair<TreeNode*, int>> s;
		s.push(make_pair(root, 1));
		while (!s.empty()) {
			auto node = s.top().first;
			auto depth = s.top().second;
			s.pop();
			if (node->left == nullptr && node->right == nullptr)
				result = min(result, depth);
			if (node->left && result > depth)
				s.push(make_pair(node->left, depth + 1));
			if (node->right && result > depth)
				s.push(make_pair(node->right, depth + 1));
		}
		return result;
	}
};