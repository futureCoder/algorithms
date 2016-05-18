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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<pair<TreeNode*,bool>> st;
        bool visited = false;
        if(root) st.push(make_pair(root,false));
        while(!st.empty())
        {
        	TreeNode *node = st.top().first;
        	visited = st.top().second;
        	st.pop();
        	if(node == NULL) continue;
        	if(visited == false)
        	{
        		st.push(make_pair(node->right,false));
        		st.push(make_pair(node->left,false));
        		st.push(make_pair(node,true));
        	}
        	else
        	{
        		ret.push_back(node->val);
        	}
        }
        return ret;
    }
};