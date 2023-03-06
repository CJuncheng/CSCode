#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lastStoneWeightII(vector<int>& stones) {
    const int len = stones.size();
    int sum = 0;
    for(int i = 0; i < len; ++i)    
        sum += stones[i];
    int target = sum/2; // dp[target] <= sum - dp[target]
    vector<int> dp(target+1, 0);
    for(int i = 0; i < len; ++i) 
        for(int j = target; j >= stones[i]; --j)
            dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
    return sum - dp[target] - dp[target];
}