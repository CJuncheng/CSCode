#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility> // pair
#include <unordered_map>
using namespace std;

//最小堆
struct CompareLess{
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
        return lhs.second > rhs.second;
    }
};
struct CompareMore{
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
        return lhs.second < rhs.second;
    }
};
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> umap;
    const int len = nums.size();
    for(int i = 0; i < len; ++i) ++umap[nums[i]];
    /* // 最小堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareLess> priQue;
    for(auto it = umap.begin(); it != umap.end(); ++it){
        priQue.push(*it);
        if(priQue.size()>(size_t)k) priQue.pop();
    }
    */
    // 最大堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareMore> priQue(umap.begin(), umap.end());

    vector<int> res(k);
    for(int i = 0; i < k; ++i){
        res[i] = priQue.top().first;
        priQue.pop();
    }
    return res;
}

int main (int argc, char* argv[])
{
    vector<int> iVec = {1,1,1,2,2,3};
    vector<int> ret = topKFrequent(iVec, 2);
    cout<< "Data: ";
    for(auto & val : ret)
        cout << val << " ";   // 返回 1
    cout << endl;
    return 0;
}