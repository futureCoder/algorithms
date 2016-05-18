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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<pair<TreeNode*,bool>> st;
        bool visited;
        st.push(make_pair(root,false));
        while(!st.empty())
        {
        	root = st.top().first;
        	visited = st.top().second;
        	st.pop();
        	if(root == NULL) continue;
        	if(visited)
        	{
        		ret.push_back(root->val);
        	}
        	else
        	{
        		st.push(make_pair(root,true));
        		st.push(make_pair(root->right,false));
        		st.push(make_pair(root->left,false));
        	}
        }
        return ret;
    }
};