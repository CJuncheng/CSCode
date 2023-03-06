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
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        const int n = numCourses;
        vector<vector<bool>> dist(n, vector<bool>(n, false));
        for(auto& prereq : prerequisites )
            dist[prereq[0]][prereq[1]] = true;
        for (int v = 0; v < n; v++) {
            for (int i = 0; i < n; i++) {
                if(i==v) continue;
                for (int j = 0; j < n; j++) {
                    if(j==v || dist[i][j]) continue;
                    if(dist[i][v] && dist[v][j])
                        dist[i][j] = true;
                }
            }
        }
        vector<bool> res;
        for(auto& query : queries)
            res.push_back(dist[query[0]][query[1]]);
        return res;
    }
};