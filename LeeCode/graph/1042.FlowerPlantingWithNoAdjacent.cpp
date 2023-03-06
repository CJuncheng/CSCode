#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for(auto& path : paths){
            adj[path[0]-1].push_back(path[1]-1);
            adj[path[1]-1].push_back(path[0]-1);
        }
        vector<int> res(n);
        for(int i = 0; i < n; ++i){
            set<int> color = {1, 2, 3, 4};
            for(int j = 0; j < adj[i].size(); ++j)
                color.erase(res[adj[i][j]]);
            res[i] = *color.begin();
        }
        return res;

    }
};