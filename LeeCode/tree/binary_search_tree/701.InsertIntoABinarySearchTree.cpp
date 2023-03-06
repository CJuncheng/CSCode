#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"

TreeNode* insertIntoBST(TreeNode* root, int val) {  
    if(root == nullptr) {
        TreeNode* node = new TreeNode(val);
        return node;
    }
    if(root->val > val) root->left = insertIntoBST(root->left, val);
    if(root->val < val) root->right = insertIntoBST(root->right, val);
    return root;
}