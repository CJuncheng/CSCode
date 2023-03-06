#include "binary_tree.h"
#include <algorithm>
#include <unordered_map> 
using namespace std;

// 暴力法， 超时
int rob(TreeNode* root) {
    if(root==nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return root->val;
    // 抢父节点
    int val1 = root->val;
    if(root->left) val1 += rob(root->left->left) + rob(root->left->right);
    if(root->right) val1 += rob(root->right->left) + rob(root->right->right);
    
    // 不抢父节点
    int val2 = rob(root->left) + rob(root->right);
    return max(val1, val2);
}

// 记忆化递推
unordered_map<TreeNode* , int> umap; // 记录计算过的结果
int rob(TreeNode* root) {
    if(root==nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return root->val;
    if (umap[root]) return umap[root]; // 如果umap里已经有记录则直接返回
    // 抢父节点
    int val1 = root->val;
    if(root->left) val1 += rob(root->left->left) + rob(root->left->right);
    if(root->right) val1 += rob(root->right->left) + rob(root->right->right);
    
    // 不抢父节点
    int val2 = rob(root->left) + rob(root->right);
    umap[root] = max(val1, val2);
    return max(val1, val2);
}

// 动态规划
// 所以dp数组（dp table）以及下标的含义：下标为0记录不偷该节点所得到的的最大金钱，下标为1记录偷该节点所得到的的最大金钱。

// 长度为2的数组，0：不偷，1：偷
vector<int> robTree(TreeNode* cur)
{
    if(cur == nullptr) return {0, 0};
    vector<int> left_res = robTree(cur->left);
    vector<int> right_res = robTree(cur->right);
    // 偷cur，那么就不能偷左右节点。
    int val1 = cur->val + left_res[0] + right_res[0];
    // 不偷cur，那么就不能偷左右节点。
    int val2 = max(left_res[0], left_res[1]) + max(right_res[0], right_res[1]);
    return {val2, val1};
}
int rob(TreeNode* root) 
{
    vector<int> res = robTree(root);
    return max(res[0], res[1]);
}

