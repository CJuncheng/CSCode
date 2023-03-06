#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

// 排列数
int combinationSum4(vector<int>& nums, int target) {
    const int len = nums.size();
    vector<int> dp(target+1, 0);
    dp[0] = 1;
    for(int j = 0; j <= target; ++j)
        for(int i = 0; i < len; ++i)
            if(j-nums[i]>=0 && dp[j] <= INT_MAX - dp[j-nums[i]])
                dp[j] += dp[j-nums[i]];
    return dp[target];
}



int main (int argc, char* argv[])
{
    vector<int> nums = {1,2,3};
    int ret = combinationSum4(nums, 4);
    cout << "Result: " << ret << endl;
    
    return 0;
}