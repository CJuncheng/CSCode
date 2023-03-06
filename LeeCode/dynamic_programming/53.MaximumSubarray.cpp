#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
// 暴力法, 超时
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    const int len = nums.size();
    for(int i = 0; i < len; ++i) {
        int sum = 0;
        for(int j = i; j < len; ++j){
            sum += nums[j];
            maxSum = sum > maxSum ? sum : maxSum;
        }
    }
    return maxSum;
}
*/

int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    int sum = 0;
    const int len = nums.size();
    for(int i = 0; i < len; ++i) {
        sum += nums[i];
        if(sum > maxSum) maxSum = sum;
        if(sum<=0) sum = 0; 
    }
    return maxSum;
}
 
/* 动态规划
 * dp[i]：包括下标i之前的最大连续子序列和为dp[i]。
 */

int maxSubArray(vector<int>& nums) {
    const int len = nums.size();
    if(len == 0) return 0;
    vector<int> dp(len);
    int res = nums[0];
    dp[0] = nums[0];
    for(int i = 1; i < len; ++i) {
        dp[i] = max(dp[i-1]+nums[i], nums[i]);
        if(dp[i] > res) res = dp[i];
    }
    return res;
}


int main (int argc, char* argv[])
{
   
    vector<int> iVec = {-2,1,-3,4,-1,2,1,-5,4};
    int ret = maxSubArray(iVec);
    cout << "Result: " << ret << endl;
    
    return 0;
}