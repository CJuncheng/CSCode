#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> degree(n);
        unordered_map<int, vector<int>> adjTab;
        vector<int> res;
        for(int i = 0; i < edges.size(); ++i){
            int u = edges[i][0],v = edges[i][1];
            ++degree[u], ++degree[v];
            adjTab[u].push_back(v);
            adjTab[v].push_back(u);
        }
        queue<int> que;
        for(int i = 0; i< n; ++i) 
            if(degree[i]==1) que.push(i);
        while(!que.empty()){
            res.clear();
            int queSize = que.size();
            for(int i = 0; i < queSize; ++i){
                int tmp = que.front(); que.pop();
                res.push_back(tmp);
                //--degree[tmp];
                for(int neighbor : adjTab[tmp]){
                    --degree[neighbor];
                    if(degree[neighbor]==1) que.push(neighbor);
                }
            }
        }
        return res;
    }
};