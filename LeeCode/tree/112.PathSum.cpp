#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <utility> // pair
#include <unordered_map>
#include "binary_tree.h"
using namespace std;

bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == nullptr) return false;
    stack<pair<TreeNode*, int>> st;
    st.push(make_pair(root, root->val));
    while(!st.empty()) {
        pair<TreeNode*, int> curPair = st.top(); st.pop();
        if(!curPair.first->left&&!curPair.first->right&&curPair.second==targetSum) return true;
        if(curPair.first->right) st.push(make_pair(curPair.first->right, curPair.second+curPair.first->right->val));
        if(curPair.first->left) st.push(make_pair(curPair.first->left, curPair.second+curPair.first->left->val));
    }
    return false;
}

bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) return false;
    if (!root->left && !root->right && sum == root->val)  return true;

    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}