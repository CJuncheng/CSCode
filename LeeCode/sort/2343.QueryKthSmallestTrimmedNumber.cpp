#include <iostream>
#include <algorithm>
#include <string_view>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        const int len = nums.size();
        const int valLen = nums[0].size();
        vector<int> idx(len);
        for(int i = 0; i < len; ++i) idx[i] = i;
        int rounds = queries.size();
        vector<int> res;
        for(int i = 0; i < rounds; ++i){
            const int k = queries[i][0], t = queries[i][1];
            sort(idx.begin(), idx.end(), [&nums, valLen, t](int& a, int& b){
                //string_view sa(nums[a].data() + valLen - t);
                //string_view sb(nums[b].data() + valLen - t);
                //return tie(sa, a) < tie(sb, b);
            });
            res.push_back(idx[k-1]);
        }
        return res;
}

vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
    const int len = nums.size();
    const int valLen = nums[0].size();
    vector<vector<int>> vec(valLen+1);
    // vecs[i][j] 表示基数排序第 i 轮中第 j 小的数对应的下标
    for(int i = 0; i < len; ++i) vec[0].push_back(i);
    for(int i = 1; i <= valLen; ++i){
        vector<vector<int>> buckets(10);
        // 把第 i - 1 轮的结果，根据 nums 中右数第 i 位数，依次放入桶中
        for(int x : vec[i-1]) buckets[nums[x][valLen-i]-'0'].push_back(x);
        // 把每个桶的结果连接起来，成为第 i 轮的结果
        for(int j = 0; j<10; ++j)
            for(int val : buckets[j]) vec[i].push_back(val);
    }
    vector<int> res;
    for(auto & q : queries) res.push_back(vec[q[1]][q[0]-1]);
    return res;
}



