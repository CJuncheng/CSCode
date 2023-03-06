#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"

TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return root;
    TreeNode* succ = nullptr; //实际被删除节点的接替者
    if(root->val==key) { // 找到节点
        if(root->left==nullptr) 
            succ = root->right;
        else if(root->right==nullptr)
            succ = root->left;
        else {
            TreeNode* leftMost = root->right; // 找右子树最左面的节点
            while(leftMost->left) leftMost = leftMost->left;
            leftMost->left = root->left;
            succ = root->right;
        }
        delete root; return succ;
    }
    if (root->val > key) root->left = deleteNode(root->left, key);
    if (root->val < key) root->right = deleteNode(root->right, key);
    return root;
}