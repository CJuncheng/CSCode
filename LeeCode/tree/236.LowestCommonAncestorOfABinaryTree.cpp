#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"




TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    if(root == p || root == q || root == nullptr) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left == nullptr) return right;
    if(right == nullptr) return left;
    return root;
}