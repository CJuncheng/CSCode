#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool canPartition(vector<int>& nums) {
    const int len = nums.size();
    int sum = 0;
    for(int i = 0; i < len; ++i)    
        sum += nums[i];
    if(sum&0x1) return false;
    int target = sum/2;
    vector<int> dp(10001, 0);
    for(int i = 0; i < len; ++i) 
        for(int j = target; j >= nums[i]; --j)
            dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
    return dp[target]==target ?  true : false;
}