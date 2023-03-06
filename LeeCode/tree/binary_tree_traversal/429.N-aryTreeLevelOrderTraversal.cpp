#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "binary_tree.h"

using namespace std;
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;
    queue<Node*> que;
    que.push(root);
    while(!que.empty()){
        vector<int> tVec;
        const size_t len = que.size();
        for(size_t i = 0; i < len; ++i){
            Node* tNode = que.front(); que.pop();
            tVec.push_back(tNode->val);
            for(size_t j = 0; j < tNode->children.size(); ++j)
                if(tNode->children[j]) que.push(tNode->children[j]);
        }
        res.push_back(tVec);
    }
    return res;
}

int main (int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl; 
   
    return 0;

}