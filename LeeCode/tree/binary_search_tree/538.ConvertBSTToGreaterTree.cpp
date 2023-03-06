
#include "binary_tree.h"

int pre = 0;
TreeNode* bstToGst(TreeNode* root) {
    if(root == nullptr) return root;
    bstToGst(root->right);
    root->val += pre;
    pre = root->val;
    bstToGst(root->left);
    return root;
}