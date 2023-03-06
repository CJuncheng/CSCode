#include <iostream>
#include <vector>
using namespace std;

// 会使用并查集(连通图分支)
class Solution {
private:
    int find(vector<int>& parent, int node){
        if(parent[node]!=node)
            parent[node] = find(parent, parent[node]);
        return parent[node];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int len = edges.size();
        vector<int> parent(len+1);
        for(int i = i; i <= len; ++i)
            parent[i] = i; // 初始化并查集
        for(vector<int>& edge : edges){
            if(find(parent, edge[0])!=find(parent, edge[1]))
                parent[find(parent, edge[0])] = find(parent, edge[1]); // 合并两个并查集
            else return edge;
        }
        return  vector<int>{};

    }
};