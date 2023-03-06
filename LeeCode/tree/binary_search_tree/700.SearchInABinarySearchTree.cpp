#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"
  
// 迭代
TreeNode* searchBST(TreeNode* root, int val) {
    while(true){
        if(!root || val==root->val) return root;
        root = val < root->val ? root->left : root->right;
    }
}
// 递归
TreeNode* searchBST(TreeNode* root, int val) {
    if(!root || val==root->val) return root;
    TreeNode* res = val<root->val ? searchBST(root->left, val) : searchBST(root->right, val);
    return res;
}