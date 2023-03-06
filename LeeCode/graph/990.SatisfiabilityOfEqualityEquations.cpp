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
    vector<int> parent;
    int find(int x) // 压缩路径
    {
        return parent[x]==x?x:parent[x] = find(parent[x]); 
    }
    void union_(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot!=yRoot){
            parent[xRoot] = yRoot;
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26, 0);
        iota(parent.begin(), parent.end(), 0);
        
        for (const string& str: equations) {
            if (str[1] == '=') {
                int idx1 = str[0] - 'a';
                int idx2 = str[3] - 'a';
                union_(idx1, idx2);
            }
        }
        
        for (const string& str: equations) {
            if (str[1] == '!') {
                int idx1 = str[0] - 'a';
                int idx2 = str[3] - 'a';
                if (find(idx1) == find(idx2)) {
                    return false;
                }
            }
        }
        return true;
    }
};