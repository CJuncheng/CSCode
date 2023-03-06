#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"

TreeNode* trav_I(vector<int>& nums, int left, int right)
{
    if(left>=right) return nullptr;
    int mid = left + (right- left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = trav_I(nums, left, mid);
    root->right = trav_I(nums, mid+1, right);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return trav_I(nums, 0, nums.size());
}