
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
};

int binTreeMaxDepth(TreeNode* node){
    if(!node) return nullptr;
    return 1 + max(binTreeMaxDepth(node->left), binTreeMaxDepth(node->right));
}

int binTreeMaxDepthIter(TreeNode* root){
    if(!node) return nullptr;
    queue<TreeNode*> que;
    int depth = 0;
    que.push(node);
    while(!que.empty) {
        const int n = que.size();
        for(int i = 0; i < n; ++i){
            TreeNode* curNode = que.front(); que.pop();
            if(curNode->left) que.push(curNode->left);
            if(curNode->right) que.push(curNode->right);
        }
        ++depth;
    }
    return depth;
}


int main(int argc, char* argv[])
{
    TreeNode* root;
    int maxDepth = binTreeMaxDepth(root);
    cout << "Bin Tree Max Depth is: " << maxDepth << endl;

    // 迭代实现
    int maxDepthIter = binTreeMaxDepthIter(root);
    cout << "Bin Tree Max Depth is: " << maxDepthIter << endl;

    return 0;
}