#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int singleNumber(vector<int>& nums) {
    /*
    if(nums.size() < 2) return nums[0];
    sort(nums.begin(), nums.end()); 
    int count = 1;
    for(auto it = nums.cbegin()+1; it != nums.cend(); ++it, count = 1) {
        while(*it == *(it-1)){ ++count; ++it;}
        if(count==1) return *(it-1);
        if(it == nums.cend() - 1) return *it;
    }
    return 0;
    */
    // 按位异或 （满足交换律）
    int x = 0;
    for(auto & i : nums)
        x ^= i;
    return x;
}


int main (int argc, char* argv[])
{
    vector<int> nums = {2, 2, 1, 1, 3, 4, 4};
    int ret = singleNumber(nums);
    std::cout << ret << endl;
    return 0;
}