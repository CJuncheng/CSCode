#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// 其实就是把环拆成两个队列，一个是从0到n-1，另一个是从1到n，然后返回两个结果最大的。
/*
int robRange(vector<int>& nums, int start, int end) {
    if(start==end) return nums[start];
    vector<int> dp(nums.size(), 0);
    dp[start] = nums[start];
    dp[start+1] = max(nums[start], nums[start+1]);
    for(int i = start+2; i <= end; ++i)
        dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
    return dp[end];
}   

int rob(vector<int>& nums) {
    const int len = nums.size();
    if(len == 0) return 0;
    if(len == 1) return nums[0];
    return max(robRange(nums, 0, len-2), robRange(nums, 1, len-1));
}
*/
//优化
inline
int robRange(vector<int>& nums, int start) {
    const int len = nums.size()-1;
    if(len==1) return nums[start];
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[start];
    dp[1] = max(nums[start], nums[start+1]);
    for(int i = 2; i < len; ++i)
        dp[i] = max(dp[i-2] + nums[start+i], dp[i-1]);
    return dp[len-1];
}   

int rob(vector<int>& nums) {
    const int len = nums.size();
    if(len == 0) return 0;
    if(len == 1) return nums[0];
    return max(robRange(nums, 0), robRange(nums, 1));
}

int main (int argc, char* argv[])
{
    vector<int> nums = {1,2,1,1};
    int ret = rob(nums);
    cout << "Result: " << ret << endl;
    
    return 0;
}