// 原地哈希
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <unordered_map>

using namespace std;

//缺失的第一个整数是 [1, len + 1] 之间，
int firstMissingPositive(vector<int>& nums) {
    const int len = nums.size();
    for(int i = 0; i < len; ++i){
        while(nums[i]>=1 && nums[i]<=len && nums[i]!=nums[nums[i]-1])
            swap(nums[i],  nums[nums[i]-1]);
    }
    for(int i = 0; i < len; ++i)
        if(nums[i] != i+1) return i+1;
    return len+1;

}