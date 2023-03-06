#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 动态规划
 * 0 状态一：买入股票状态（今天买入股票，或者是之前就买入了股票然后没有操作）
 * 卖出股票状态，这里就有两种卖出股票状态
 *   1 状态二：两天前就卖出了股票，度过了冷冻期，一直没操作，今天保持卖出股票状态
 *   2 状态三：今天卖出了股票
 * 3 状态四：今天为冷冻期状态，但冷冻期状态不可持续，只有一天！
 * dp[i][j]中 i表示第i天，j为 [0 - 3] 五个状态，dp[i][j]表示第i天状态j所剩最大现金。
 */
int maxProfit(vector<int>& prices) {
    const int len = prices.size();
    if(len == 0) return 0;
    vector<vector<int>> dp(len, vector<int>(4));
    dp[0][0] = - prices[0];
    for(int i = 1; i < len; ++i) {
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][3], dp[i-1][1])-prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
        dp[i][2] = dp[i-1][0] + prices[i];
        dp[i][3] = dp[i-1][2];
    }
    return max(dp[len-1][3], max(dp[len-1][1], dp[len-1][2]));
}

int main (int argc, char* argv[])
{
    vector<int> iVec = {1,2,3,0,2};
    int ret = maxProfit(iVec);
    cout << "Result: " << ret << endl;
    
    return 0;
}