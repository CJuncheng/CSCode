#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"

//笨蛋法
inline
void travIn_R(TreeNode* parent, vector<int>& res)
{
    if(parent == nullptr) return;
    travIn_R(parent->left, res);
    res.push_back(parent->val);
    travIn_R(parent->right, res);
}
bool isValidBST(TreeNode* root) {
    vector<int> res;
    travIn_R(root, res);
    const size_t len = res.size();
    for(int i = 1; i < len; ++i) 
        if(res[i] <= res[i-1]) return false;
    return true;
}

//依然中序遍历

long elem = LONG_MIN;
bool isValidBST(TreeNode* root) {
    if(root == nullptr) return true;
    bool left = isValidBST(root->left);
    if(elem < root->val) elem = root->val;
    else return false;
    bool right = isValidBST(root->right);
    return left && right;
}