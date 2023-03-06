#include <iostream>
#include <vector>
#include <queue>
#include "binary_tree.h"

using namespace std;
// 递归实现
bool compare(TreeNode* left, TreeNode* right)
{
    if(left == nullptr && right != nullptr) return false;
    else if(left != nullptr && right == nullptr) return false;
    else if(left == nullptr && right == nullptr) return true;
    else if(left->val != right->val) return false;
    // 此时就是：左右节点都不为空，且数值相同的情况, 才做递归
    bool outside = compare(left->left, right->right);
    bool inside = compare(left->right, right->left);
    bool isSame = outside&&inside;
    return isSame;
}
bool isSymmetric(TreeNode* root) {
    if(root == nullptr) return true;
    return compare(root->left, root->right);
}

// 迭代实现
bool isSymmetric(TreeNode* root) {
    if(root == nullptr) return true;
    queue<TreeNode*> que;
    que.push(root->left);
    que.push(root->right);
    while (!que.empty()) {
        TreeNode* left = que.front(); que.pop();
        TreeNode* right = que.front(); que.pop();
        if(!left && !right) continue;
        if(!left|| !right || left->val!=right->val) return false;
        que.push(left->left);
        que.push(right->right);
        que.push(left->right);
        que.push(right->left);
    }
    return true;
}

int main (int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl; 
   
    return 0;

}

