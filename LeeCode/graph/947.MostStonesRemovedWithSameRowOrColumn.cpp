#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <numeric>

using namespace std;

class Solution {
private:
    vector<int> parent;  // 记录节点的根
    vector<int> rank;  // 记录根节点的深度（用于优化）
    int count;
    int find(int x) {
        return parent[x]==x ? x : parent[x] = find(parent[x]);
    }
    void union_(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot!=yRoot) {
            if (rank[xRoot] < rank[yRoot]) {
                swap(xRoot, yRoot);
            }
            parent[yRoot] = xRoot;
            if (rank[xRoot] == rank[yRoot]) rank[xRoot] += 1;
            --count; //记录连通分支数
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        const int len = stones.size();
        parent.resize(len);
        rank.resize(len);
        count = len;
        for(int i = 0; i < len; ++i) parent[i] = i;
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    union_(i, j);
                }
            }
        }
        return len - count;
    }
};