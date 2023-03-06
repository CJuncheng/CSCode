#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;   

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<int, int> umap;

TreeNode*  build(vector<int>& preorder, vector<int>& inorder, int pre_root, int in_left, int in_right)
{
    if(in_left>in_right) return nullptr;
    TreeNode* root = new TreeNode(preorder[pre_root]);
    int in_root = umap[preorder[pre_root]];
    root->left = build(preorder, inorder, pre_root+1, in_left, in_root-1);
    root->right = build(preorder, inorder, pre_root+in_root-in_left+1, in_root+1, in_right);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    for(int i = 0; i < inorder.size();++i)  umap[inorder[i]]=i;
    build(preorder, inorder, 0, 0, inorder.size()-1);
}

/*
class Solution {
public:
    unordered_map<int,int> map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 将中序序列用哈希表存储，便于查找根节点
        for(int i = 0;i < inorder.size();i++)
            map[inorder[i]] = i;
        // 传入参数：前序,中序，前序序列根节点，中序序列左边界，中序序列右边界
        return build(preorder,inorder,0,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int pre_root,int in_left,int in_right){
        if(in_left > in_right)
            return NULL;
        TreeNode* root = new TreeNode(preorder[pre_root]);
        // 根节点在中序序列中的位置，用于划分左右子树的边界
        int in_root = map[preorder[pre_root]];
        // 左子树在前序中的根节点位于：pre_root+1,左子树在中序中的边界：[in_left,in_root-1]
        root->left = build(preorder,inorder,pre_root+1,in_left,in_root-1);
        // 右子树在前序中的根节点位于：根节点+左子树长度+1 = pre_root+in_root-in_left+1
        // 右子树在中序中的边界：[in_root+1,in_right]
        root->right = build(preorder,inorder,pre_root+in_root-in_left+1,in_root+1,in_right);
        return root;
    }
};
*/