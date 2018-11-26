#ifndef __algorighmsbasic__hpp__
#define __algorighmsbasic__hpp__
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <cstdio>
using namespace std;

class CTest
{
public:
	CTest(void);
	~CTest(void);
	int GetValue();
};

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
}TreeNode;

typedef struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}ListNode;

ListNode* make_List(string data);

TreeNode* make_Tree(string data);

TreeNode* getTreeNode(string str);

TreeNode *deserialize(const string &data);

void deserialize(const string &data, int &start, int elemNum, queue<TreeNode *> &q);

void preorder(TreeNode* root);

#endif