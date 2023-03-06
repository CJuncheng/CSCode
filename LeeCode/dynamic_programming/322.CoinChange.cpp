#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    const int len = coins.size();
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < len; ++i)
        for(int j = coins[i]; j <= amount; ++j)
            if(dp[j-coins[i]] != INT_MAX)
                dp[j] = min(dp[j], dp[j-coins[i]] + 1);
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main (int argc, char* argv[])
{
    vector<int> coins = {1, 2, 5};
    int ret = coinChange(coins, 11);
    cout << "Result: " << ret << endl;
    
    return 0;
}