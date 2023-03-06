#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"

using namespace std;
// 0 无覆盖， 1 有相机， 2有覆盖
inline int travPost_R(TreeNode* parent, int& res)
{
    if(parent == nullptr) return 2;
    int left = travPost_R(parent->left, res);
    int right = travPost_R(parent->right, res);
    if(left == 2 && right == 2) return 0; // 情况1
    else if(left == 0 || right == 0) { // 情况2：左右节点至少有一个无覆盖
        ++res;
        return 1;
    } else return 2;                 //情况3：left == 1 || right == 1, 左右节点至少有一个有相机
}

int minCameraCover(TreeNode* root) {
    int res = 0;
    if(travPost_R(root, res) == 0) ++res; // 情况4, 根节点为无覆盖状态
    return res;

}