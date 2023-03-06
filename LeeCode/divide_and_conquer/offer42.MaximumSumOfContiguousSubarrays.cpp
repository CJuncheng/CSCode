#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// 动态规划
//dp[i]dp[i] 代表以元素 nums[i]nums[i] 为结尾的连续子数组最大和。

int maxSubArray(vector<int>& nums) {
    const int len = nums.size();
    vector<int> dp(len);
    dp[0] = nums[0];
    int maxSubSum = 0;
    for(int i = 1; i<len; ++i){
        dp[i] = dp[i - 1] > 0 ? dp[i - 1]+nums[i] : nums[i];
        maxSubSum = max(maxSubSum, dp[i]);
    }
    return maxSubSum;
}