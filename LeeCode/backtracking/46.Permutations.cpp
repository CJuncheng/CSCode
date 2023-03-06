#include <iostream>
#include <vector>
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
        if(used[i] == true ) continue; // path里已经收录的元素，直接跳过
        path.push_back(nums[i]);
        used[i]= true;
        backtracking(nums, used);
        used[i]= false;
        path.pop_back();
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return res;
}

int main (int argc, char* argv[])
{
    vector<int> ivec = {1,2,3};
    vector<vector<int>> ret = permute(ivec);
    cout << "Result: " << endl;
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
            std::cout << *it2 << " " ;
        std::cout << std::endl;
    }
    return 0;
}
