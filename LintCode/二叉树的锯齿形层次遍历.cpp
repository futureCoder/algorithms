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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        stack<TreeNode*> st;
        if(root)
        	st.push(root);
        myLevelOrder(st, false, ret);
        return ret;
    }
    void myLevelOrder(stack<TreeNode*> st, bool rightToLeft, vector<vector<int>> &ret) {
    	stack<TreeNode*> nextLayer;
    	vector<int> tmp;
    	if(rightToLeft) {
    		while(!st.empty()) {
    			auto node = st.top();
    			st.pop();
    			if(node->right)
    				nextLayer.push(node->right);
    			if(node->left)
    				nextLayer.push(node->left);
    			tmp.push_back(node->val);
    		}
    	}
    	else {
    		while(!st.empty()) {
    			auto node = st.top();
    			st.pop();
    			if(node->left)
    				nextLayer.push(node->left);
    			if(node->right)
    				nextLayer.push(node->right);
    			tmp.push_back(node->val);
    		}
    	}
    	if(!tmp.empty())
    		ret.push_back(tmp);
    	if(!nextLayer.empty())
    		return myLevelOrder(nextLayer, !rightToLeft, ret);
    }
};