#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxProfit(vector<int>& prices) {
    int profit = 0;
    for(int i = 1; i < (int)prices.size(); ++i) 
        profit += max(prices[i]-prices[i-1], 0);
    return profit;
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
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
        dp[i][1] = max(dp[i-1][1], prices[i]+dp[i-1][0]);
    }
    return dp[len-1][1];
}


int main (int argc, char* argv[])
{
   
    vector<int> iVec = {1,2};
    int ret = maxProfit(iVec);
    cout << "Result: " << ret << endl;
    
    return 0;
}