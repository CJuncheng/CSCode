#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& time : times)
            adj[time[0]-1].emplace_back(make_pair(time[1]-1, time[2]));
        k=k-1;
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq; 
       
        vector<int> dist(n, INT_MAX); 
        vector<bool> visited(n, false);
        pq.push(make_pair(0, k)); 
        dist[k] = 0; 
        
        while (!pq.empty()) 
        { 
            int u = pq.top().second; 
            pq.pop(); 
            if (visited[u]) continue;
            
            visited[u] = true;
            for (auto x : adj[u]) 
            { 
                int v = x.first; 
                int weight = x.second;   
                if (dist[v] > dist[u] + weight) 
                { 
                        
                    dist[v] = dist[u] + weight; 
                    pq.push(make_pair(dist[v], v)); 
                } 
            } 
        } 
        auto res = *max_element(dist.begin(), dist.end());
        return res==INT_MAX ? -1 : res;
    }
};