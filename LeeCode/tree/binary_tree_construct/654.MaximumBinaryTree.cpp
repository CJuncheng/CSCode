#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"

template<typename Iter> 
TreeNode* traversal(Iter first, Iter last)
{
    if(first == last) return nullptr;
    auto max_pos = max_element(first, last);
    TreeNode* root = new TreeNode(*max_pos);
    root->left = traversal(first, max_pos);
    root->right = traversal(next(max_pos), last);
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return traversal(nums.begin(), nums.end());
}