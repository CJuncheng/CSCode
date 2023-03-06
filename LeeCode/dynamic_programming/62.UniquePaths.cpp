#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    //dp[0][0] = 1;
    //for(int col = 1; col < n; ++col) dp[0][col] = 1; //初始化第一行
    //for(int row = 1; row < m; ++row) dp[row][0] = 1; //初始化第一列
    for(int row  = 1; row < m; ++row)
        for(int col = 1; col < n; ++col)
            dp[row][col] = dp[row][col-1] + dp[row-1][col];
    return dp[m-1][n-1];
}

int main (int argc, char* argv[])
{
    
    int ret = uniquePaths(1, 1);
    cout << "Result: " << ret << endl;
    
    return 0;
}