#include "algorithmsBasic.hpp"

TreeNode* make_Tree(string data) {
	if (data.size() == 0)
		return NULL;
	int start = 0, elemNum = 1;
	return deserialize(data);
}

TreeNode* getTreeNode(string str) {
	if (str.size() == 0)
		return NULL;
	if ('#' == str[0])
		return NULL;
	return new TreeNode(stoi(str));
}

TreeNode *deserialize(const string &data) {
	if (0 == data.size())
		return NULL;
	int idx = data.find(",", 0);
	TreeNode *root;
	queue<TreeNode*> q;
	if (NULL != (root = getTreeNode(data.substr(0, idx))))
		q.push(root);
	if (!root)
		return root;
	int elemNum = 2;
	++idx;
	deserialize(data, idx, elemNum, q);
	return root;
}

void deserialize(const string &data, int &start, int elemNum, queue<TreeNode*> &q) {
	if (!(start < (int)data.size())) {
		while (!q.empty())
			q.pop();
		return;
	}
	int idx;
	for (int i = 1; i < elemNum;) {
		TreeNode *root = q.front();
		q.pop();
		if (NULL == root) {
			i += 2;
			continue;
		}
		idx = data.find(",", start);
		if (NULL != (root->left = getTreeNode(data.substr(start, idx - start))))
			q.push(root->left);
		start = idx + 1;
		++i;
		if (!(start < (int)data.size())) {
			while (!q.empty())
				q.pop();
			return;
		}
		idx = data.find(",", start);
		if (NULL != (root->right = getTreeNode(data.substr(start, idx - start))))
			q.push(root->right);
		start = idx + 1;
		++i;
	}
	deserialize(data, start, elemNum << 1, q);
}

void preorder(TreeNode* root) {
	if (NULL == root)
		return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}