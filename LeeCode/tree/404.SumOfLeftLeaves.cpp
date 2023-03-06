#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include "binary_tree.h"
using namespace std;

// 迭代，先序遍历
int sumOfLeftLeaves(TreeNode* root) {
    int res = 0;
    if(root==nullptr) return 0;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* curNode = st.top(); st.pop();
        if(curNode->right) st.push(curNode->right);
        if(curNode->left) {
            if(curNode->left->left==nullptr && curNode->left->right==nullptr)
                res += curNode->left->val;
            st.push(curNode->left);
        }
    }
    return res;
}

//递归
int sumOfLeftLeaves(TreeNode* root) {
    int res = 0;
    if(root==nullptr) return 0;
    if(root->left!=nullptr&&root->left->left==nullptr && root->left->right==nullptr)
        res = root->left->val;
    return res + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}