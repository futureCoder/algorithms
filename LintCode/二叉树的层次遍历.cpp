/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 
 
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        vector<int> tmp;
        TreeNode *last, *nLast;
        if(root) {
        	q.push(root);
        	last = root;
        }
        while(!q.empty()) {
        	TreeNode *node = q.front();
        	q.pop();
        	tmp.push_back(node->val);
        	if(node->left) {
        		q.push(node->left);
        		nLast = node->left;
        	}
        	if(node->right) {
        		q.push(node->right);
        		nLast = node->right;
        	}
        	if(node == last) {
        		ret.push_back(tmp);
        		tmp.clear();
        		last = nLast;
        	}
        }
        return ret;
    }
};
