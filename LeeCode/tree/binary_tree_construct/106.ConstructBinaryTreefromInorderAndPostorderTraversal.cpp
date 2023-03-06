#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"

using namespace std;

template<typename Iter> 
TreeNode* traversal(Iter in_first, Iter in_last, Iter post_first, Iter post_last)
{
    if(in_first == in_last) return nullptr;
    if(post_first == post_last) return nullptr;
    const auto val = *prev(post_last);
    TreeNode* root = new TreeNode(val);

    auto delimiter = find(in_first, in_last, val);
    auto in_left_size = distance(in_first, delimiter);
    auto post_left_last = next(post_first, in_left_size);
    root->left = traversal(in_first, delimiter, post_first, post_left_last);
    root->right = traversal(next(delimiter), in_last, post_left_last, prev(post_last));
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(begin(inorder), end(inorder), begin(postorder), end(postorder));
}