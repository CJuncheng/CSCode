#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <numeric>
using namespace std;

class Solution {
    void dfs(const vector<vector<int>>& adj, vector<int>& visited, int cur){
        visited[cur] = true;
        for(auto neigh : adj[cur]){
            if(!visited[neigh]) dfs(adj, visited, neigh);
        }
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n, false);
        dfs(adj, visited, source);
        return visited[destination]==true; 
    }
};