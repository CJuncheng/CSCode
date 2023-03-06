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
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        const int len = edges.size();
        for(int i = 0; i < len; ++i){
            adj[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        vector<double> prob(n, 0);
        vector<int> visited(n, false);
        priority_queue<pair<double, int>> pq; 

        pq.push(make_pair(1, start));
        prob[start] = 1;
        /*
        while(!pq.empty()){
            auto u = pq.top().second; pq.pop();
            if(visited[u]) continue;
            visited[u] = true;
            for(auto& [v, succPro] : adj[u]){
                if(prob[v] < prob[u] * succPro){
                    prob[v] = prob[u] * succPro;
                    pq.push(make_pair(prob[v], v));
                }
            }
        }
        */
        return prob[end];
    }
};