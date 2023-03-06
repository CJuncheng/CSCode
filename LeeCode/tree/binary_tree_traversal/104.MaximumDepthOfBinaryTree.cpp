#include <iostream>
#include <vector>
#include <queue>
#include "binary_tree.h"

using namespace std;

// 迭代，层次遍历
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int depth = 0;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        vector<int> tVec;
        const size_t len = que.size();
        for(size_t i = 0; i < len; ++i){
            TreeNode* curNode = que.front(); que.pop();
            if(curNode->left) que.push(curNode->left);
            if(curNode->right) que.push(curNode->right);
        }
        ++depth;
    }
    return depth;
}

// 递归
int getDepth(TreeNode* root) 
{
    if(root == nullptr) return 0;
    int leftdepth = getDepth(root->left);
    int rightdepth = getDepth(root->right);
    int depth = 1 + max(leftdepth, rightdepth);
    return depth;
}
int maxDepth(TreeNode* root) 
{
    return getDepth(root);
}



int main (int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl; 
   
    return 0;

}