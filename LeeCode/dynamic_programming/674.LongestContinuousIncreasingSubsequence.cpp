#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 动态规划
 * dp[i]表示i之前包括i的以nums[i]结尾最长上升子序列的长度
 * if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1)
 */
/*
int findLengthOfLCIS(vector<int>& nums) {
    const int len = nums.size();
    if(len <= 1) return len;
    vector<int> dp(len, 1);
    int res = 0;
    for(int i = 1; i < len; ++i){
        int j = i-1;
        while(j >= 0 && nums[j+1] > nums[j]){ 
            dp[i] = max(dp[i], dp[j]+1);
            --j;
        }
        res = max(res, dp[i]);
    }
    return res;
}
*/
// 贪心

int findLengthOfLCIS(vector<int>& nums) {
    const int len = nums.size();
    if(len <= 1) return len;
    int res = 0;
    for(int i = 0; i < len-1; ++i){
        int count = 1;
        while (nums[i+1] > nums[i]) {
            ++count;  ++i;
        }
        res = max(res, count);
    }
    
   /*
    int count = 1;
    for(int i = 0; i < len-1; ++i){
        if (nums[i+1] > nums[i]) ++count;
        else count = 1;
        res = max(res, count);
    }
    */
    return res;
}

int main (int argc, char* argv[])
{
   
    vector<int> iVec = {1,3,5,4,7};
    int ret = findLengthOfLCIS(iVec);
    cout << "Result: " << ret << endl;
    
    return 0;
}