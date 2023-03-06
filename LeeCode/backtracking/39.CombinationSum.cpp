#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;
void backTracking(vector<int>& candidates, int target, size_t start, int sum){
    if(sum>=target){
        if(sum==target)
            res.push_back(path);
        return;
    }
    for(size_t i = start; i < candidates.size(); ++i){
        path.push_back(candidates[i]); 
        sum += candidates[i];
        backTracking(candidates, target, i, sum); // i 不用加 1，表示元素可以重复选取
        sum -= candidates[i];
        path.pop_back(); 
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    backTracking(candidates, target, 0, 0);
    return res;
}

int main (int argc, char* argv[])
{
    vector<int> candidates = {2,3,6,7};
    vector<vector<int>> ret = combinationSum(candidates, 7);
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
            std::cout << *it2 << " " ;
        std::cout << std::endl;
    }

   
    return 0;
}