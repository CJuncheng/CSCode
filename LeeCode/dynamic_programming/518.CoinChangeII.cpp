#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int change(int amount, vector<int>& coins) {
    const int len = coins.size();
    vector<int> dp(amount+1, 0);
    dp[0] = 1;
    for(int i = 0; i < len; ++i)
        for(int j = coins[i]; j <= amount; ++j)
            dp[j] += dp[j-coins[i]];
    return dp[amount];
}


int main (int argc, char* argv[])
{
    vector<int> coins = {1, 2, 5};
    int ret = change(5, coins);
    cout << "Result: " << ret << endl;
    
    return 0;
}