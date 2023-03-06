#include <vector>
#include <iostream>
#include <algorithm>

class UnionFindSet{
public:
    std::vector<int> parent; // 记录节点的根
    std::vector<int> rank;   // 记录根节点的深度（用于优化）
    std::vector<int> size;   // 记录每个连通分量的节点个数
    std::vector<int> len;    // 记录每个连通分量里的所有边长度
    int num;            // 记录节点个数
    UnionFindSet(int n): parent(n), rank(n), len(n, 0), size(n, 1), num(n) {
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    }
    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    int merge(int x, int y, int length) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot != yRoot) {
            if (rank[xRoot] < rank[yRoot]) {
                std::swap(xRoot, yRoot);
            }
            parent[yRoot] = xRoot;
            if (rank[xRoot] == rank[yRoot]) rank[xRoot] += 1;
            // yRoot 的父节点设置为 xRoot,同时将 yRoot 的节点数和边长度累加到 xRoot,
            size[xRoot] += size[yRoot];
            len[xRoot] += len[yRoot] + length;
            // 如果某个连通分量的节点数 包含了所有节点，直接返回边长度
            if (size[xRoot] == num) return len[xRoot];
        }
        return -1;
    }
};
struct Edge {
    int start; // 顶点1
    int end;   // 顶点2
    int len;   // 长度
};

class Solution {
public:
    int kruskal(const std::vector<std::vector<int>>& points) {
        int res = 0;
        int n = points.size();
        std::vector<Edge> edges;
        // 建立点-边式数据结构
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                Edge edge = {i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])};
                edges.emplace_back(edge);
            }
        }
        // 按边长度排序
        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
            return a.len < b.len;
        });

        UnionFindSet unionFindSet(n);
        // 连通分量合并
        for (auto& e : edges) {
           res = unionFindSet.merge(e.start, e.end, e.len);
           if (res != -1) return res;
        }
        return 0;
    }
};

