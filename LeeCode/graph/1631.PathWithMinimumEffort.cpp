#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <tuple>
using namespace std;
class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0},{1, 0}, {0, -1}, {0, 1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int m = heights.size(), n = heights[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>> , greater<tuple<int, int, int>>> pq;
        vector<int> dist(m*n, INT_MAX); 
        vector<bool> visited(m*n, false);
        dist[0] = 0;
        pq.push(make_tuple(0, 0, 0));
        /*
        while (!pq.empty()) {
           auto [d, x, y] = pq.top(); pq.pop();
            if(visited[x*n + y]) continue;
            if(x==m-1&&y==n-1) break;
            visited[x*n + y] = true;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx>=0 && nx<m && ny>=0 && ny<n && max(d, abs(heights[nx][ny]-heights[x][y]))<dist[nx*n + ny])
                {
                    dist[nx*n + ny] = max(d, abs(heights[nx][ny]-heights[x][y]));
                    pq.push(make_tuple(dist[nx*n + ny], nx, ny));
                }
            }
        }
        */
        return dist[m*n-1];

    }

};