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
private:
    vector<int> parent;
    vector<int> rank;
    int count;
    int find(int x){
        return parent[x]==x ? x : parent[x] = find(parent[x]);
    }
    void union_(int x, int y){
        int xRoot = find(x), yRoot = find(y);
        if(xRoot!=yRoot){
            if(rank[xRoot]<rank[yRoot])
                swap(xRoot, yRoot);
            parent[xRoot] =yRoot;
            if(rank[xRoot]==rank[yRoot]) rank[xRoot]+=1;
            --count;
        }

    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        parent.resize(n);
        rank.resize(n);
        count = n;
        for(int i = 0; i < n; ++i) parent[i]=i;
        for(int i = 0; i < n; ++i){
            if(leftChild[i]!=-1){
                if(find(i)==find(leftChild[i])) return false;
                union_(i, leftChild[i]);
            }
            if(rightChild[i]!=-1){
                if(find(i)==find(rightChild[i])) return false;
                union_(i, rightChild[i]);
            }
        }
        // 入度判断根节点是否唯一
        vector<int> inDegree(n);
        int nRoots = 0;
        for(int i = 0; i < n; ++i){
            if(leftChild[i]!=-1) ++inDegree[leftChild[i]];
            if(rightChild[i]!=-1) ++inDegree[rightChild[i]];
        }
        for(int i = 0; i < n; ++i)
            if(inDegree[i]==0) ++nRoots;
        if(count>1 || nRoots>1) return false;
        return true;
    }
};