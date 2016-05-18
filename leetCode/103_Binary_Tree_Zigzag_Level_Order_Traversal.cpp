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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int elemNum = 0,level = 0;
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        if(root)
        {
            ++elemNum;
            q.push(root);
        }
        while(elemNum != 0)
        {
            int tmpNum = 0;
            vector<int> tmp;
            for(int i = 0; i < elemNum; ++i)
            {
                root = q.front();
                q.pop();
                tmp.push_back(root->val);
                if(root->left)
                {
                    ++tmpNum;
                    q.push(root->left);
                }
                if(root->right)
                {
                    ++tmpNum;
                    q.push(root->right);
                }
            }
            if(level & 0x1)
            	reverse(tmp.begin(), tmp.end());
            ret.push_back(tmp);
            ++level;
            elemNum = tmpNum;
        }
        return ret;
    }
};