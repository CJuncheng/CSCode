#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;   

class Solution {
    struct CompareMore{ //最大堆， 队列中元素按从大到小排序
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
            return lhs.second < rhs.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(auto& val : nums) ++umap[val];
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareMore> priQue(umap.begin(), umap.end());
        vector<int> res;
        while(k--){
            auto tmp = priQue.top();
            priQue.pop();
            res.push_back(tmp.first);
        }
        return res;
    }
};