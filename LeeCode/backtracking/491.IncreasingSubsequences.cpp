#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> res;
vector<int> path;

void backtracking(const vector<int>& nums, int start)
{
    if(path.size()>1)
        res.push_back(path);
    //if(start>=(int)nums.size()) return;
    unordered_set<int> uset;
    for(int i = start; i < (int)nums.size(); ++i){
        if((!path.empty()&& nums[i] < path.back()) || uset.find(nums[i]) != uset.end()) continue;
        uset.insert(nums[i]);
        path.push_back(nums[i]);
        backtracking(nums, i+1);
        path.pop_back();
    }
}
vector<vector<int>> findSubsequences(vector<int>& nums) {
    backtracking(nums, 0);
    return res;
}

int main (int argc, char* argv[])
{
    vector<int> ivec = {4,6,7,7};
    vector<vector<int>> ret = findSubsequences(ivec);
    cout << "Result: " << endl;
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
            std::cout << *it2 << " " ;
        std::cout << std::endl;
    }
    return 0;
}
