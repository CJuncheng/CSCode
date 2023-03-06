#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"

//笨蛋法
inline
void travIn_R(TreeNode* parent, vector<int>& ivec)
{
    if(parent == nullptr) return;
    travIn_R(parent->left, ivec);
    ivec.push_back(parent->val);
    travIn_R(parent->right, ivec);
}
int getMinimumDifference(TreeNode* root) {
    vector<int> ivec;
    travIn_R(root, ivec);
    const size_t len = ivec.size();
    int res = INT_MAX;
    for(int i = 1; i < len; ++i) 
        res = min(res, ivec[i] - ivec[i-1]);
    return res;
}

//另一种中序遍历

inline
void DFS(TreeNode* parent, int& pre, int& res)
{
    if(parent == nullptr) return;
    DFS(parent->left, pre, res);
    if(pre!=INT_MIN) 
        res = min(res, parent->val - pre);
    pre = parent->val;
    DFS(parent->right, pre, res);
}
int getMinimumDifference(TreeNode* root) {
    int res = INT_MAX, pre = INT_MIN;
    DFS(root, pre, res);
    return res;
}