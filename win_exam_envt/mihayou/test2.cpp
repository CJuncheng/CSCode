
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dfs(int node, vector<vector<int>>& adj, vector<bool>& vst, vector<int>& dist, int k) {
    vst[node] = true;
    int maxCnt = 0;
    if(adj[node].size()==1 && dist[node] <= k) maxCnt += k - dist[node];
    for (int neigh : adj[node]) {
        if (!vst[neigh]) {
            dist[neigh] = dist[node] + 1;
            if (dist[neigh] <= k) {
                ++maxCnt;
            }
            maxCnt += dfs(neigh, adj, vst, dist, k);
        }
    }
    return maxCnt;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> vst(n + 1, false);
    vector<int> dist(n + 1, 0);
    
    int res = dfs(1, adj, vst, dist, k);
    
    cout << res + 1  << endl;
    
    return 0;
}
