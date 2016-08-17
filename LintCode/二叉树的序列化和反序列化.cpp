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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        string str;
        serialize(root, str);
        return str;
    }
    void serialize(TreeNode *root, string &str) {
        if(!root) {
            str.append("#!");
            return ;
        }
        str.append(to_string(root->val) + "!");
        serialize(root->left, str);
        serialize(root->right, str);
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {

    }
    TreeNode *deserialize(string data, int &start, int end) {
        if('!' == data[start]) {
            start += 2;
            return NULL;
        }
        int idx = data.find("!", start);
        if(1 == idx - start && data[start])
            
    }
};
