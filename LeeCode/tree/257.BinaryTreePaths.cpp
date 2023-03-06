#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include "binary_tree.h"
using namespace std;

// 迭代，先序遍历
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    stack<TreeNode*> treeSt;
    stack<string> treePath;
    if(root==nullptr) return res;
    treeSt.push(root);
    treePath.push(to_string(root->val));
    while(!treeSt.empty()) {
        TreeNode* curNode = treeSt.top(); treeSt.pop();
        string curPath = treePath.top(); treePath.pop();
        if(!curNode->left&&!curNode->right) res.push_back(curPath);
        if(curNode->right) {
            treeSt.push(curNode->right);
            treePath.push(curPath+"->"+to_string(curNode->right->val));
        }
        if(curNode->left) {
            treeSt.push(curNode->left);
            treePath.push(curPath+"->"+to_string(curNode->left->val));
        }
    }
    return res;
}