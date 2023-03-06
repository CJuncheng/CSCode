#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<vector<int>>& graph, int idx)
    {
        if(idx == graph.size()-1){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < graph[idx].size(); ++i){
            path.push_back(graph[idx][i]);
            dfs(graph, graph[idx][i]);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0);
        return res;
    }
};