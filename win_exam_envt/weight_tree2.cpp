#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int dfs(vector<vector<int>>& graph, vector<int>& colors, int node) {
    colors[node] = 1; // 将当前节点染红
    int count = 1; // 当前染红节点的数量
    for (int i = 0; i < graph[node].size(); i++) {
        int neighbor = graph[node][i];
        if (colors[neighbor] == 0 && isPrime(colors[node] + colors[neighbor])) {
            count += dfs(graph, colors, neighbor);
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    
    vector<int> colors(n, 0);
    int maxRedNodes = 0;
    for (int i = 0; i < n; i++) {
        if (colors[i] == 0) {
            maxRedNodes = max(maxRedNodes, dfs(graph, colors, i));
        }
    }
    
    cout << maxRedNodes << endl;
    
    return 0;
}