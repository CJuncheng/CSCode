#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "binary_tree.h"

using namespace std;
/*
// 递归
inline
void travPost_R(TreeNode* parent, vector<int>& res)
{
    if(parent == nullptr) return;
    travPost_R(parent->left, res);
    travPost_R(parent->right, res);
    res.push_back(parent->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    travPost_R(root, res);
    return res;
}
*/


// 迭代
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;
    stack<TreeNode*> S;
    S.push(root);  // root不为空
    while(!S.empty()){
        root = S.top();
        S.pop();
        if(root){
            res.push_back(root->val);
            if(root->left); S.push(root->left);
            if(root->right); S.push(root->right);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}



int main (int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl; 
   
    return 0;

}