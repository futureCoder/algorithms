/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class TreePrinter {
public:
    vector<vector<int> > printTree(TreeNode* root) {
    	vector<vector<int>> ret;
        queue<TreeNode*> q;
        vector<int> tmp;
        if(root)
        	q.push(root);
        int cur = 1, next = 0;
        auto addNextLayer = [&](const TreeNode *root, int &next) {
        	if(root->left) {
        		q.push(root->left);
        		++next;
        	}
        	if(root->right) {
        		q.push(root->right);
        		++next;
        	}
        };
        while(!q.empty()) {
        	auto curNode = q.front();
        	q.pop();
        	tmp.push_back(curNode->val);
        	addNextLayer(curNode, next);
        	--cur;
        	if(0 == cur) {
        		ret.push_back(tmp);
        		tmp.clear();
        		cur = next;
        		next = 0;
        	}
        }
        return ret;
    }
};