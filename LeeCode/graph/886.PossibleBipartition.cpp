#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

/*
// 并查集
class Solution {
public:
    int parent[4010];
    int find(int x){
        return x==parent[x] ? x : parent[x]=find(parent[x]);
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(int i = 0; i <= n*2; ++i) parent[i]=i;
        for(auto& i : dislikes){
            int a = find(i[0]), b = find(i[1]);
            if(a==b) return false;
            parent[find(a+n)] = b;
            parent[find(b+n)] = a;
        }
        return true;
    }
};
*/

// dfs + 染色
class Solution {
private:
    bool dfs(int curNode, int curColor, const vector<vector<int>>&adj, vector<int>& color)
    {
        color[curNode] = curColor;
        for(auto& nextNode : adj[curNode]){
            if(color[nextNode]&&color[curNode]==color[nextNode]) return false;
            if(!color[nextNode]&& !dfs(nextNode, 3^curColor, adj, color)) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        vector<int> color(n, 0);
        for(auto& i : dislikes){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        
        for(int i = 0; i < n; ++i)
            if(!color[i]&&!dfs(i, 1, adj, color)) return false;
        return true;
    }
};