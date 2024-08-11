

#include <iostream>
#include <vector>

struct Node {
    int val;
    Node* left;
    Node* right
    Node(): val(0), left(nullptr), right(nullptr) {}
}

void dfs(Node* node, int height, int lastHeight, int lastVal){
    if(node == nullptr) return;
    ++height;
    dfs(node->left, height, lastHeight, lastVal);
    dfs(node->right, height, lastHeight, lastVal);
    if(height > lastHeight){
        lastHeight = height;
        lastVal = node->val;
    }
}

int main(int argc, char* argv[]){
    Node* root;
    int lastVal = 0, lastHeight = 0;
    dfs(root, 0, lastHeight, lastVal);

 
    return 0;
}