#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(vector<vector<int>>& graph, int v, int color, vector<int>& colors) // 对顶点v 着 color 色
    {
        if(colors[v]!=0) return colors[v] == color;
        colors[v] = color;
        for(int n : graph[v])
            if(!dfs(graph, n, -color, colors)) return false;
        return true;

    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int len = graph.size();
        vector<int> colors(len); // 0-uncolored; 1; -1
        for(int i = 0; i < len; ++i)
        if(colors[i]==0&&!dfs(graph, i, 1, colors)) return false;
        return true;
    }
};

// 需要多种方法比较
