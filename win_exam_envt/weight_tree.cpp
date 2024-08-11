#include <iostream>
#include <vector>

using namespace std;
/*
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// 深度优先搜索
void dfs(vector<vector<int>>& graph, vector<int>& weights, vector<bool>& visited, int node, int& count) {
    visited[node] = true;
    count++;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor] && isPrime(weights[node] + weights[neighbor])) {
            dfs(graph, weights, visited, neighbor, count);
        }
    }
}

// 计算最多可以染红的节点数
int maxRedNodes(vector<vector<int>>& graph, vector<int>& weights) {
    int n = graph.size();
    vector<bool> visited(n, false);
    int maxCount = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int count = 0;
            dfs(graph, weights, visited, i, count);
            maxCount = max(maxCount, count);
        }
    }
    return maxCount;
}


int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int> weights(n);
    for(int i = 0; i < n; ++i)
        cin >> weights[i];
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; ++i){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    int maxRed = maxRedNodes(adj, weights);
    cout << maxRed << endl;

    return 0;
}
*/



bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
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

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int> weights(n);
    for(int i = 0; i < n; ++i)
        cin >> weights[i];
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; ++i){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int> colors(n, 0);
    int maxRedNodes = 0;
    for (int i = 0; i < n; i++) {
        if (colors[i] == 0) {
            maxRedNodes = max(maxRedNodes, dfs(adj, colors, i));
        }
    }
    
    cout << maxRedNodes << endl;

    return 0;
}