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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        typedef pair<TreeNode*, bool> node;
        stack<node> s;
        if(root)
            s.push(make_pair(root, false));
        while(!s.empty()) {
            TreeNode *cur = s.top().first;
            bool visited = s.top().second;
            s.pop();
            if(visited) {
                ret.push_back(cur->val);
            }
            else {
                s.push(make_pair(cur, true));
                if(cur->right)
                    s.push(make_pair(cur->right, false));
                if(cur->left)
                    s.push(make_pair(cur->left, false));
            }
        }
        return ret;
    }
};