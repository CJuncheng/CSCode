#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <utility> // pair
#include <unordered_map>
#include "binary_tree.h"
using namespace std;

// 迭代， 先序遍历
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    if(!root) return res;
    stack<pair<TreeNode*, int>> stPair;
    stack<vector<int>> stVec;
    stPair.push(make_pair(root, root->val));
    vector<int> vec; vec.push_back(root->val);
    stVec.push(vec);
    while(!stPair.empty()){
        pair<TreeNode*, int> curPair = stPair.top(); stPair.pop();
        vector<int> curVec = stVec.top(); stVec.pop();
        if(!curPair.first->left&&!curPair.first->right&&curPair.second==targetSum) 
            res.push_back(curVec);
        if(curPair.first->right) {
            stPair.push(make_pair(curPair.first->right, curPair.second+curPair.first->right->val));
            curVec.push_back(curPair.first->right->val);
            stVec.push(curVec);
            curVec.pop_back(); // 回溯
        }
        
        if(curPair.first->left) {
            stPair.push(make_pair(curPair.first->left, curPair.second+curPair.first->left->val));
            curVec.push_back(curPair.first->left->val);
            stVec.push(curVec);
            curVec.pop_back();
        }
    }
    return res;
}

// dfs递归
vector<vector<int>> res;
vector<int> path;

void dfs(TreeNode* root, int targetSum)
{
    if(root==nullptr) return;
    path.push_back(root->val);
    targetSum -= root->val;
    if(!root->left&&!root->right&&targetSum==0) res.push_back(path);
    dfs(root->left, targetSum);
    dfs(root->right, targetSum);
    path.pop_back();

}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    dfs(root, targetSum);
    return res;
}