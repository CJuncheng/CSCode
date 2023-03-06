#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> res;
vector<int> path;
void backtracking(const vector<int>& nums, vector<bool>& used)
{
    if(path.size()==nums.size()){
        res.push_back(path);
        return;
    }
    for(int i = 0; i < (int)nums.size(); ++i){
        if(used[i] == true ) continue;
        if(i>0&&nums[i-1]==nums[i]&&used[i-1]==false) continue; // 同层节点不重复遍历，只遍历一个
        path.push_back(nums[i]);
        used[i]= true;
        backtracking(nums, used);
        used[i]= false;
        path.pop_back();
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtracking(nums, used);
    return res;
}

int main (int argc, char* argv[])
{
    vector<int> ivec = {1,1,3};
    vector<vector<int>> ret = permuteUnique(ivec);
    cout << "Result: " << endl;
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
            std::cout << *it2 << " " ;
        std::cout << std::endl;
    }
    return 0;
}
