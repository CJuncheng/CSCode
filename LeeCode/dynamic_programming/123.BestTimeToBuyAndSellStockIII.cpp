#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/* 动态规划
 * 0 没有操作
 * 1 第一次买入
 * 2 第一次卖出
 * 3 第二次买入
 * 4 第二次卖出
 * dp[i][j]中 i表示第i天，j为 [0 - 4] 五个状态，dp[i][j]表示第i天状态j所剩最大现金。
 */
int maxProfit(vector<int>& prices) {
    const int len = prices.size();
    if(len == 0) return 0;
    vector<vector<int>> dp(len, vector<int>(5));
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0]; 
    for(int i = 1; i < len; ++i) {
        dp[i][0] = dp[i-1][0];
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
        dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
        dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
    }
    return dp[len-1][4];
}


int main (int argc, char* argv[])
{
   
    vector<int> iVec = {3,3,5,0,0,3,1,4};
    int ret = maxProfit(iVec);
    cout << "Result: " << ret << endl;
    
    return 0;
}