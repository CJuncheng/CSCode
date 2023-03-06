#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"

int countNodes(TreeNode* root) {
    if(root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}