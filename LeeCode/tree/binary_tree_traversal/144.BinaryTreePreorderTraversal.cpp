#include <iostream>
#include <vector>
#include <stack>
#include "binary_tree.h"

using namespace std;
inline
/*
// 递归
void travPre_R(TreeNode* parent, vector<int> res)
{
    if(parent == nullptr) return;
    res.push_back(parent->val);
    travPre_R(parent->left, res);
    travPre_R(parent->right, res);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    travPre_R(root, res);
    return res;
}
*/
// 迭代
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;
    stack<TreeNode*> S;
    S.push(root);  // root不为空
    while(!S.empty()){
        root = S.top();
        S.pop();
        if(root){
            res.push_back(root->val);
            if(root->right); S.push(root->right);
            if(root->left); S.push(root->left);
        }
    }
    return res;
}



int main (int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl; 
   
    return 0;

}

