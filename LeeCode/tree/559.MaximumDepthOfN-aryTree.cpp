#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "binary_tree.h"

using namespace std;

//递归
int maxDepth(Node* root) 
{
    if (root==nullptr) return 0;
    int depth = 0;
    for(int i = 0; i < root->children.size(); ++i) 
    {
        depth = max(depth, maxDepth(root->children[i]));
    }
    return depth + 1;
}

//迭代，层次遍历
int maxDepth(Node* root) 
{
    if (root==nullptr) return 0;
    queue<Node*> que;
    que.push(root);
    int depth = 0;
    while(!que.empty()) {
        ++depth;
        const int len = que.size();
        for(int i = 0; i < len; ++i){
            Node* curNode = que.front(); que.pop();
            for(int j = 0; j < curNode->children.size(); ++j)
                if(curNode->children[j]) que.push(curNode->children[j]);
        }
    }
    return depth;
}

int main (int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl; 
   
    return 0;

}