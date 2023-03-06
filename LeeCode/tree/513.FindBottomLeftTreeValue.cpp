#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include "binary_tree.h"
using namespace std;

// 迭代，层次遍历
int findBottomLeftValue(TreeNode* root) {
    if(root==nullptr) return 0;
    int res = 0; //保存每层第一个元素
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()) {
        const int len = que.size();
        for(int i = 0; i < len; ++i){
            TreeNode* curNode = que.front(); que.pop();
            if(i==0) res = curNode->val;
            if(curNode->left) que.push(curNode->left);
            if(curNode->right) que.push(curNode->right);
        }
    }
    return res; //返回最后一层最左边元素
}

// 递归
int maxDepth = INT_MIN;
int res = 0;
void traversal(TreeNode* root, int depth)
{
    if(root->left==nullptr && root->right==nullptr) {
        if(depth > maxDepth){
            maxDepth = depth;
            res = root->val;
        }
        return;
    }
    if(root->left) {
        ++depth;
        traversal(root->left, depth);
        --depth;
    }
    if(root->right) {
        ++depth;
        traversal(root->right, depth);
        --depth;
    }
    return;

}
int findBottomLeftValue(TreeNode* root) {
    if(root == nullptr) return 0;
    traversal(root, 0);
    return res;  
}