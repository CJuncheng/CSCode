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
 * ......
 * dp[i][j]中 i表示第i天，j为 [0 - 4] 五个状态，dp[i][j]表示第i天状态j所剩最大现金。
 */
int maxProfit(int k, vector<int>& prices) {
    const int len = prices.size();
    if(len == 0) return 0;
    vector<vector<int>> dp(len, vector<int>(2*k+1));
    for(int j = 1; j < 2*k; j+=2) 
        dp[0][j] = -prices[0];
    for(int i = 1; i < len; ++i) {
        dp[i][0] = dp[i-1][0];
        for(int j = 0; j < 2*k; j+=2) {
            dp[i][j+1] = max(dp[i-1][j+1], dp[i-1][j] - prices[i]);
            dp[i][j+2] = max(dp[i-1][j+2], dp[i-1][j+1] + prices[i]);
        }
    }
    return dp[len-1][2*k];
}

int main (int argc, char* argv[])
{
   
    vector<int> iVec = {3,3,5,0,0,3,1,4};
    int ret = maxProfit(2, iVec);
    cout << "Result: " << ret << endl;
    
    return 0;
}