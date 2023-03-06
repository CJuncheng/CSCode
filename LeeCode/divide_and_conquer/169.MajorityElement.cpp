#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;   
   
int majorityElement(vector<int>& nums) {
/*
    // 哈希表
    const int len = nums.size();
    unordered_map<int, int> umap;
    for(auto val : nums) ++umap[val];
    //int res = 0;
    for(auto it = umap.begin(); it != umap.end(); ++it){
        if(it->second > (len/2)) return it->first;
    }
    return -1;
*/
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];

}


int main(int argc, char* argv[])
{
    vector<int> vec = {3,2,3};
    int ret = majorityElement(vec);
    cout << ret << endl;
}