#include <stdio.h>
#include <vector>
#include <malloc.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorder(struct TreeNode* root){
	if(root == NULL) return ;
	printf("%d-",root->val);
	preorder(root->left);
	preorder(root->right);
	return ;
}

void inorder(struct TreeNode* root){
	if(root == NULL) return ;
	inorder(root->left);
	printf("%d-",root->val);
	inorder(root->right);
	return ;
}

    struct TreeNode* reBuilt(vector<int> pre,vector<int> in, int &i, int in_i, int in_j){
        if(i >= pre.size()) return NULL;
        int a;
        struct TreeNode *tmp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        tmp->val = pre[i];
        for(a = in_i;a <= in_j; ++a)
            if(in[a] == pre[i]) break;
        if(a == in_i) tmp->left = NULL;
        else tmp->left = reBuilt(pre, in, ++i, in_i, a-1);
        if(a == in_j) tmp->right = NULL;
        else tmp->right = reBuilt(pre, in, ++i, a+1, in_j);
                printf("\n------\n");
        inorder(tmp);
                printf("\n--------\n");
        return tmp;
    }

    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        if(pre.empty()) return NULL;
		struct TreeNode* root;
		int i = 0;
        root = reBuilt(pre, in, i, 0, in.size() - 1);
        return root;
    }




int main(){
	vector<int> pre{1,2,4,7,3,5,6,8};
	vector<int> in{4,7,2,1,5,3,8,6};
	struct TreeNode* root = reConstructBinaryTree(pre,in);
	printf("\nPREORDER\n");
	preorder(root);
	printf("\nINORDER\n");
	inorder(root);
	return 0;
}
