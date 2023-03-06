#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private: 
    unordered_map<Node*, Node*> hash;
    Node* dfs(Node* node){
        if(hash[node]) return hash[node];               //node节点已经被访问过了,直接从哈希表hash中取出对应的克隆节点返回。
        Node* clone = new Node(node->val);              //克隆节点
        hash[node] = clone;                             //建立源节点到克隆节点的映射
        for(Node* neighbor : node->neighbors)           //克隆边
            clone->neighbors.push_back(dfs(neighbor));
        return clone;

    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        return dfs(node);
    }
};