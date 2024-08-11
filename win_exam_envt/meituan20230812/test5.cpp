 #include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

bool isPerfectSquare(int num) {
    int sqrtNum = sqrt(num);
    return sqrtNum * sqrtNum == num;
}

void dfs(int node, int parent, const vector<int>& values, unordered_map<int, vector<int>>& graph, int& maxRedNodes) {
    int currentValue = values[node - 1];
    int prevParent = -1; // To keep track of previous parent (not counting the direct parent)
    
    for (int neighbor : graph[node]) {
        if (neighbor == parent) {
            prevParent = parent;
            continue;
        }
        
        dfs(neighbor, node, values, graph, maxRedNodes);
        
        if (prevParent != -1) {
            // Check if the product of current node's value and the neighbor's value is a perfect square
            if (isPerfectSquare(currentValue * values[neighbor - 1])) {
                maxRedNodes += 2;
                prevParent = -1; // Reset the previous parent
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int maxRedNodes = 0;
    dfs(1, -1, values, graph, maxRedNodes); // Start DFS from the root node
    
    cout << maxRedNodes << endl;
    
    return 0;
}