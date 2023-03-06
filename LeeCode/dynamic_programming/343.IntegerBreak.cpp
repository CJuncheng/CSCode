#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int integerBreak(int n) {
    vector<int> dp(n+1);
    dp[2] = 1;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j < i-1; ++j){
            dp[i] = max(dp[i], max((i-j)*j, dp[i-j]*j)); // 状态方程没有特别理解
        }
    return dp[n];
}

int main (int argc, char* argv[])
{
    int ret = integerBreak(10);
    cout << "Result: " << ret << endl;
    
    return 0;
}