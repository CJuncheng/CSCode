#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<vector<int>> backGraph(n);
        for(auto& connection : connections){
            graph[connection[0]].push_back(connection[1]);
            backGraph[connection[1]].push_back(connection[0]);
        }
        vector<bool> visited(n, false);
        int res=0;
        queue<int> que;
        que.push(0);
        visited[0] = true;
    
        while(!que.empty()){
            int i = que.front(); que.pop();
            for(auto j : graph[i]){
                if(!visited[j]){
                    visited[j] = true;
                    ++res;
                    que.push(j);
                }
            }
            for(auto k : backGraph[i]){
                if(!visited[k]){
                    visited[k] =true;
                    que.push(k);
                }
            }
        }
    
        return res;

    }
};