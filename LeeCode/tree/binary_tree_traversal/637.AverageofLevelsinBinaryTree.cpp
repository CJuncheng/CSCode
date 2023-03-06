#include <iostream>
#include <vector>
#include <queue>
#include "binary_tree.h"

using namespace std;
  
vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    if (root == nullptr) return res;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        double tVal = 0;
        const size_t len = que.size();
        for(size_t i = 0; i < len; ++i){
            TreeNode* tNode = que.front(); que.pop();
            tVal += tNode->val;
            if(tNode->left) que.push(tNode->left);
            if(tNode->right) que.push(tNode->right);
        }
        res.push_back(tVal/len);
    }
    return res;
}

int main (int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl; 
   
    return 0;

}