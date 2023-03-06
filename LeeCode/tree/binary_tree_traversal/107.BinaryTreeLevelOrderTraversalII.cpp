#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "binary_tree.h"

using namespace std;
  
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        vector<int> curVec;
        const size_t len = que.size();
        for(size_t i = 0; i < len; ++i){
            TreeNode* curNode = que.front(); que.pop();
            curVec.push_back(curNode->val);
            if(curNode->left) que.push(curNode->left);
            if(curNode->right) que.push(curNode->right);
        }
        res.push_back(curVec);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main (int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl; 
   
    return 0;

}