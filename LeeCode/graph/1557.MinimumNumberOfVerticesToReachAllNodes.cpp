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
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n);
        for(auto& edge : edges)
            ++inDegree[edge[1]];
        vector<int> res;
        for(int i = 0; i < n; ++i)
            if(inDegree[i]==0) res.push_back(i);
        return res;
    }
};