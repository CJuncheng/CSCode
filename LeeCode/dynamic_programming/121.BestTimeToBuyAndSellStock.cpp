#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 贪心算法
int maxProfit(vector<int>& prices) {
    const int len = prices.size();
    int low = INT_MAX, res = 0;
    for(int i = 0; i < len; ++i) {
        low = min(low, prices[i]);
        res = max(res, prices[i] - low);
    }
    return res;
}


/* 动态规划
 * dp[i][0] 表示第i天持有股票所得最多现金 
 * dp[i][1] 表示第i天不持有股票所得最多现金
*/
int maxProfit(vector<int>& prices) {
    const int len = prices.size();
    if(len == 0) return 0;
    vector<vector<int>> dp(len, vector<int>(2));
    dp[0][0] -= prices[0];
    dp[0][1] = 0; 
    for(int i = 1; i < len; ++i) {
        dp[i][0] = max(dp[i-1][0], -prices[i]);
        dp[i][1] = max(dp[i-1][1], prices[i]+dp[i-1][0]);
    }
    return dp[len-1][1];
}
int main (int argc, char* argv[])
{
    vector<int> ivec = {7,1,5,3,6,4};
    int ret = maxProfit(ivec);
    cout << "Result: " << ret << endl;
    
    return 0;
}