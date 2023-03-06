#include <iostream>
#include <vector>
#include <queue>
#include "binary_tree.h"

using namespace std;

//迭代，层次遍历
int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int depth = 0;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        ++depth;
        const size_t len = que.size();
        for(size_t i = 0; i < len; ++i){
            TreeNode* curNode = que.front(); que.pop();
            if(curNode->left) que.push(curNode->left);
            if(curNode->right) que.push(curNode->right);
            if(!curNode->left && !curNode->right)return depth; 
        }
    }
    return depth;
}

// 递归
int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    if(root->left==nullptr&&root->right!=nullptr)
        return 1 + minDepth(root->right);
    if(root->left!=nullptr&&root->right==nullptr)
        return 1 + minDepth(root->left);
    return 1+ min(minDepth(root->right), minDepth(root->left));
}

int main (int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl; 
   
    return 0;

}