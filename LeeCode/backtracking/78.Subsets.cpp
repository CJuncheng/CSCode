#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;
void backtracking(const vector<int>& nums, int start)
{
    res.push_back(path);
    //if(start>=(int)nums.size()) return;
    for(int i = start; i < (int)nums.size(); ++i){
        path.push_back(nums[i]);
        backtracking(nums, i+1);
        path.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    backtracking(nums, 0);
    return res;
}

int main (int argc, char* argv[])
{
    vector<int> ivec = {1,2,3};
    vector<vector<int>> ret = subsets(ivec);
    cout << "Result: " << endl;
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
            std::cout << *it2 << " " ;
        std::cout << std::endl;
    }

    return 0;
}