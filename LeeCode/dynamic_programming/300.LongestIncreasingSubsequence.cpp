#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 动态规划
 * dp[i]表示i之前包括i的以nums[i]结尾最长上升子序列的长度
 * if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1)
 */
int lengthOfLIS(vector<int>& nums) {
    const int len = nums.size();
    if(len <= 1) return len;
    vector<int> dp(len, 1);
    int res = 0;
    for(int i = 1; i < len; ++i){
        for(int j = 0; j<i; ++j)
            if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
        res = max(res, dp[i]);
    }
    return res;
}

int main (int argc, char* argv[])
{
   
    vector<int> iVec = {10,9,2,5,3,7,101,18};
    int ret = lengthOfLIS(iVec);
    cout << "Result: " << ret << endl;
    
    return 0;
}