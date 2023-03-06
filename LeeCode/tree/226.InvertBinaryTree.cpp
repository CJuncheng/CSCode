#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "binary_tree.h"

using namespace std;

//递归
TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) return root;
    std::swap(root->left, root->right); 
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

// 迭代
TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) return root;
    stack<TreeNode*> S;
    S.push(root);
    while(!S.empty()) {
        TreeNode* curNode = S.top(); S.pop(); 
        std::swap(curNode->left, curNode->right); 
        if(curNode->right) S.push(curNode->right); 
        if(curNode->left) S.push(curNode->left); 
    }
    return root;
}

int main (int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl; 
   
    return 0;

}

