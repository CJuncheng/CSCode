#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    const int len = nums.size();
    int sum = 0;
    for(int i = 0; i < len; ++i) sum += nums[i];
    if(abs(target) > sum || (sum+target)&0x1) return 0; // 此时没有方案
    int bagSize = (sum+target)/2;
    if(bagSize < 0 ) return 0;
    vector<int> dp(bagSize+1, 0); // 填满j（包括j）这么大容积的包，有dp[j]种方法
    dp[0] = 1;
    for(int i = 0; i < len; ++i) 
        for(int j = bagSize; j >= nums[i]; --j)
            dp[j] += dp[j-nums[i]];
    return dp[bagSize];
}
















