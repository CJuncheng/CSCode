#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int numTrees(int n) {
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= i; ++j)
            dp[i] += dp[i-j] * dp[j-1];
    return dp[n];
}

int main (int argc, char* argv[])
{
    int ret = numTrees(3);
    cout << "Result: " << ret << endl;
    
    return 0;
}