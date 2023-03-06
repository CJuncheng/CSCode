#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// dp[i]：考虑下标i（包括i）以内的房屋，最多可以偷窃的金额为dp[i]。
int rob(vector<int>& nums) {
    const int len = nums.size();
    if(len == 0) return 0;
    if(len == 1) return nums[0];
    vector<int> dp(len, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < len; ++i)
        dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
    return dp[len-1];
}

int main (int argc, char* argv[])
{
    vector<int> nums = {1,2,3,};
    int ret = rob(nums);
    cout << "Result: " << ret << endl;
    
    return 0;
}