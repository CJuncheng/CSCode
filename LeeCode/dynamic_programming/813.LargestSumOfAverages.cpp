#include <vector>
#include <algorithm>
using namespace std; 
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        const int len = nums.size();
        vector<vector<double>> dp(len+1, vector<double>(K+1));
        // 前缀和
        vector<double> sum(len+1);
        for(int i = 1; i<=len; ++i) 
            sum[i] = sum[i-1] + nums[i-1];
        // k=1;
        for(int i = 1; i<=len;++i)
            dp[i][1] = sum[i]/i;
        // k>1
        for(int i = 1; i<=len; ++i)
            for(int k = 2; k<=K; ++k)
                for(int j = 1; j < i; ++j){
                    double avg = (sum[i]-sum[j])/(i-j);
                    dp[i][k] = max(dp[i][k], dp[j][k-1]+avg);
                }
        return dp[len][K];
    }
};