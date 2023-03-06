#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> path;
void backTracking(vector<int>& candidates, int target, size_t start, int sum){
    if(sum==target){
        res.push_back(path);
        return;
    }
    for(size_t i = start; i < candidates.size(); ++i){
        if(sum + candidates[i] > target) return; // 大剪枝
        if (i > start && candidates[i] == candidates[i - 1]) continue;  // 小剪枝
        path.push_back(candidates[i]); 
        sum += candidates[i];
        backTracking(candidates, target, i+1, sum); // i 不用加 1，表示元素可以重复选取
        sum -= candidates[i];
        path.pop_back(); 
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // 从小到大，保证有序
    backTracking(candidates, target, 0, 0);
    return res;
}

int main (int argc, char* argv[])
{
    vector<int> candidates = {10,1,2,7,6,1,5};
    vector<vector<int>> ret = combinationSum2(candidates, 8);
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
            std::cout << *it2 << " " ;
        std::cout << std::endl;
    }
    return 0;
}