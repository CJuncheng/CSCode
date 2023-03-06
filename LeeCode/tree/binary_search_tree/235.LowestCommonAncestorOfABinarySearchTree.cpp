#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"

//迭代
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    while(root) {
        if(root->val > p->val && root->val > q->val)
            root = root->left;
        else if(root->val < p->val && root->val < q->val)
             root = root->right;
        else return root; //一定能找到公共祖先
    }
    return nullptr;
}

//递归

TreeNode* travIn_R(TreeNode* parent, TreeNode* p, TreeNode* q)
{
    if(parent == nullptr) return parent;
    if(parent->val > p->val && parent->val > q->val)
        return travIn_R(parent->left, p, q);
    if(parent->val < p->val && parent->val < q->val)
        return travIn_R(parent->right, p, q);
    return parent;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    return travIn_R(root, p, q);
}
