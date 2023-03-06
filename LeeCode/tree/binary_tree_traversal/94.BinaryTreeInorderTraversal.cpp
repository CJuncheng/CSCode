#include <iostream>
#include <vector>
#include <stack>
#include "binary_tree.h"

using namespace std;
/*
// 递归
inline
void travIn_R(TreeNode* parent, vector<int>& res)
{
    if(parent == nullptr) return;
    travIn_R(parent->left, res);
    res.push_back(parent->val);
    travIn_R(parent->right, res);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    travIn_R(root, res);
    return res;
}
*/

// 迭代
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;
    stack<TreeNode*> S;
    while(true){
        while (root) { //从当前节点出发，沿左分支不断深入，直至没有左分支的节点
            S.push(root);
            root = root->left;
        } //当前节点入栈后随即向左侧分支深入，迭代直到无左孩子
        if (S.empty())
            break; //直至所有节点处理完毕
        root = S.top(); 
        S.pop();
        if(root) {
            res.push_back(root->val);
            root = root->right;    
        } 
    }
    return res;
}

int main (int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl; 
   
    return 0;

}

