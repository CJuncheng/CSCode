#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"

int getHeight(TreeNode* root)
{
    if(root == nullptr) return 0;
    int leftHeight = getHeight(root->left);
    if(leftHeight==-1) return -1;
    int rightHeight = getHeight(root->right);
    if(rightHeight==-1) return -1;
    return abs(leftHeight-rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode* root) {
    if(root==nullptr) return true;
    return getHeight(root) ==-1 ? false : true;
}