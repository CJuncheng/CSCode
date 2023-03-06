#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    const int len = cost.size();
    vector<int> dp(len);
    dp[0] = cost[0]; //dp[i]的定义：到达第i个台阶所花费的最少体力为dp[i]。
    dp[1] = cost[1];
    for(int i = 2; i < len; ++i)
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    return min(dp[len - 1], dp[len-2]);
}

int main (int argc, char* argv[])
{
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int ret = minCostClimbingStairs(cost);
    cout << "Result: " << ret << endl;
    
    return 0;
}