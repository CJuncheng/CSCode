#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
// 贪心
int maxProfit(vector<int>& prices, int fee) {
    int profit = 0;
    const int len = prices.size();
    if(len < 2) return profit;
    int minPrice = prices[0];
    for(int i = 1; i < len; ++i) {
        if(minPrice > prices[i]) minPrice = prices[i];
        //if(prices[i]>=minPrice&&prices[i]<=minPrice+fee) continue;
        if(prices[i]>minPrice+fee) { //盈利
           profit += prices[i] - minPrice - fee;
           minPrice = prices[i] - fee; // 实际卖出，更新 minPrice;
        }
    }
    return profit;
}
*/

/* 动态规划
 * dp[i][0] 表示第i天持有股票所得最多现金。 dp[i][1] 表示第i天不持有股票所得最多现金
 */
int maxProfit(vector<int>& prices, int fee) {
    const int len = prices.size();
    vector<vector<int>> dp(len, vector<int>(2));
    dp[0][0] = -prices[0];
    for(int i = 1; i < len; ++i) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i] - fee);
    }
    return max(dp[len-1][0], dp[len-1][1]);
}

int main (int argc, char* argv[])
{
   
    vector<int> iVec = {1, 3, 2, 8, 4, 9};
    int ret = maxProfit(iVec, 2);
    cout << "Result: " << ret << endl;
    
    return 0;
}