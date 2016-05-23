class Solution {
public:
	void connect(TreeLinkNode *root) {
		connect(root, NULL);
	}
private:
	void connect(TreeLinkNode *root, TreeLinkNode *sibling) {
		if (root == nullptr)
			return;
		else
			root->next = sibling;
		connect(root->left, root->right);
		if (sibling)
			connect(root->right, sibling->left);
		else
			connect(root->right, nullptr);
	}
};