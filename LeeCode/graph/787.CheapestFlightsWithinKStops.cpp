#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //设dp[i][cur]表示到达当前cur城市最多经过i站中转路线的最便宜的价格
        //则dp[i][cur] = min(dp[i][cur],dp[i-1][last] + cost)
        //last:表示上一站，cost表示从last到cur的花费。
        //初始化：dp[i][src] = 0 ，无论经过多少次，初始出发地的总花费均为0,其余为INF
        //最终结果：dp[k+1][dst]
        const int INF = 1e9;
        vector<vector<int>> dp(k+2, vector<int>(n, INF));
        for(int i = 0; i <=k+1; ++i) dp[i][src] = 0;
        for(int i = 1; i <= k+1; ++i)
            for(auto& flight : flights)
                dp[i][flight[1]] = min(dp[i][flight[1]], dp[i-1][flight[0]]+flight[2]);
        return dp[k+1][dst] >= INF ? -1 : dp[k+1][dst];
    }
};