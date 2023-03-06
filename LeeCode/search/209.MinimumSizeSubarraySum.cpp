#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    const int len = nums.size();
    int res = INT_MAX;
    int sum = 0, i = 0; // i： 滑动窗口起始位置
    for(int j = 0; j < len; ++j){
        sum += nums[j];
        while(sum>=target){
            int subLen = j-i+1;
            if(subLen<res) res = subLen;
            sum -=nums[i++];
        }
    }
    return res == INT_MAX ? 0 : res;
}