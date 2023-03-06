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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        for(int i = 0; i<n; ++i) distance[i][i] = 0;
        for(auto& edge : edges) 
            distance[edge[0]][edge[1]] = distance[edge[1]][edge[0]] = edge[2];

        //floyd
        for(int v = 0; v < n; ++v)
            for(int i = 0; i < n; ++i){
                if(i==v) continue;
                for(int j = 0; j < n; ++j){
                    if(j == v) continue;
                    if(distance[i][v] < INT_MAX && distance[v][j]<INT_MAX && distance[i][j] > distance[i][v] + distance[v][j])
                    distance[i][j] = distance[i][v] + distance[v][j];
                }
            }
        int minNum = INT_MAX, res = -1;
        for(int i = 0; i < n; ++i){
            int count = 0;
            for(int j = 0; j < n; ++j)
                if(i!=j&& distance[i][j]<=distanceThreshold) ++count;
            if(count<=minNum){
                minNum = count;
                res = i;
            }
        }
        return res;
    }
};