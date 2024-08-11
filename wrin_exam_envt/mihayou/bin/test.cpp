#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& distance, int k) {
    visited[node] = true;
    int maxCount = 0;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            distance[neighbor] = distance[node] + 1;
            if (distance[neighbor] <= k) {
                maxCount++;
            }
            maxCount += dfs(neighbor, adj, visited, distance, k);
        }
    }
    return maxCount;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> visited(n + 1, false);
    vector<int> distance(n + 1, 0);
    
    int maxCount = dfs(1, adj, visited, distance, k);
    
    cout << maxCount + 1 << endl;
    
    return 0;
}