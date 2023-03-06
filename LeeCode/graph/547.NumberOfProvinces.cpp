#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
    int n;
    vector<int> parent;
    void init(void)
    {
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int find(int v)
    {
        return parent[v]==v ? v : parent[v] = find(parent[v]);
    }
    void union_(int u, int v)
    {
        int uRoot = find(u);
        int vRoot = find(v);
        if(uRoot!=vRoot) parent[uRoot] = vRoot; 
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        parent.resize(n, 0);
        init();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < i; ++j)
                if(isConnected[i][j]) union_(i,j);
        unordered_set<int> uset;
        for(int i = 0; i < n; ++i)
            uset.insert(find(i));
        return uset.size();

    }
};