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
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        typedef pair<TreeNode*, bool> node;
        stack<node> st;
        vector<int> ret;
        if(root)
        	st.push({root, false});
        while(!st.empty()) {
        	TreeNode *cur = st.top().first;
        	bool isVisit = st.top().second;
        	st.pop();
        	if(isVisit) {
        		ret.push_back(cur->val);
        	}
        	else {
        		if(cur->right)
        			st.push({cur->right, false});
        		if(cur->left)
        			st.push({cur->left, false});
        		st.push({cur, true});
        	}
        }
        return ret;
    }
};
