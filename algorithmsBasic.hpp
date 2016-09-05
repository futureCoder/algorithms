#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

TreeNode* make_Tree(string data);

TreeNode* getTreeNode(string str);

TreeNode *deserialize(const string &data);

void deserialize(const string &data, int &start, int elemNum, queue<TreeNode *> &q);

void preorder(TreeNode* root);