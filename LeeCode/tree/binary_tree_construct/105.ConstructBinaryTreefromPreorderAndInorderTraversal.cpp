#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"

using namespace std;

template<typename Iter> 
TreeNode* traversal(Iter pre_first, Iter pre_last, Iter in_first, Iter in_last)
{
    if(pre_first == pre_last) return nullptr;
    if(in_first == in_last) return nullptr;
    const auto val = *pre_first;
    TreeNode* root = new TreeNode(val);

    auto delimiter = find(in_first, in_last, val);
    auto in_left_size = distance(in_first, delimiter);
    auto pre_left_last = next(next(pre_first), in_left_size);
    root->left = traversal(next(pre_first), pre_left_last, in_first, delimiter);
    root->right = traversal(pre_left_last, pre_last, next(delimiter), in_last);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traversal(begin(preorder), end(preorder), begin(inorder), end(inorder));
}