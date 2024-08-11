#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int maxSubArray(vector<int>& nums) {
        const int len = nums.size();
        vector<int> dp(len);
        dp[0] = nums[0];
        int maxSubSum = nums[0];
        for(int i = 1; i<len; ++i){
            dp[i] = dp[i - 1] > 0 ? dp[i - 1]+nums[i] : nums[i];
            maxSubSum = max(maxSubSum, dp[i]);
        }
        return maxSubSum;
}

int main(int argc, char* argv[])
{
    vector<vector<int>> args;
    vector<vector<int>> vecs;
    int t = 0;
    cin >> t;
    for(int i = 0; i < t; ++i){
        int n, x;
        cin >> n >> x;
        vector<int> tmp = {n, x};
        args.emplace_back(tmp);
   
        vector<int> tmp2;
        for(int j = 0; j < n; ++j){
            int val;
            tmp2.emplace_back(val);
        }
        vecs.emplace_back(tmp2);
    }
    for(int i = 0; i < t; ++i){
      int n_ = args[i][0], x_ = args[i][1];
      
      
    }
}
    