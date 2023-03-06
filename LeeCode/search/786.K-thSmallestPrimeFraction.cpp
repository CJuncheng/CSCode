#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

struct CompareLess{ //最小堆， 队列中元素按从小到大排序
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
        return lhs.first+0.0/lhs.second > rhs.first+0.0/rhs.second;
    }
};

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    unordered_map<int, int> umap;
    const int len = arr.size();
    for(int i = 0; i < len; ++i)
        umap[arr[i]] = i;
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareLess> priQue;
    for(int i = 1; i < len; ++i)
        priQue.push(make_pair(arr[0], arr[i]));
    for(int i = 0; i < k-1; ++i){
        auto tmp = priQue.top();
        priQue.pop();
        priQue.push(make_pair(arr[umap[tmp.first]+1], tmp.second));
    }
    auto tmp = priQue.top();
    return vector<int>{tmp.first, tmp.second};
}

