#include <iostream>
#include <vector>
#include <queue>
//#include "binary_tree.h"

using namespace std;
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
};

Node* connect(Node* root) {
    if (root == nullptr) return root;
    queue<Node*> que;
    que.push(root);
    while(!que.empty()) {
        const size_t len = que.size();
        Node* prevNode, *curNode; 
        for(size_t i = 0; i < len; ++i){
            if(i == 0) {
                prevNode = curNode = que.front();
                que.pop();
            } else {
                curNode = que.front(); que.pop();
                prevNode->next = curNode;
                prevNode = curNode;
            }
            if(curNode->left) que.push(curNode->left);
            if(curNode->right) que.push(curNode->right);
        }
        prevNode->next = nullptr;
    }
    return root;
}
int main (int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl; 
   
    return 0;

}