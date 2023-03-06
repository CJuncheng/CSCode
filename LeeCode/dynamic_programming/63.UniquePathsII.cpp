#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    const int nRow = obstacleGrid.size(), nCol = obstacleGrid[0].size();
    if(obstacleGrid[0][0]==1||obstacleGrid[nRow-1][nCol-1]) return 0;
    vector<vector<int>> dp(nRow, vector<int>(nCol, 0));
    dp[0][0] = 1;
    for(int col = 1; col < nCol && obstacleGrid[0][col] == 0; ++col) dp[0][col] = 1; //初始化第一行
    for(int row = 1; row < nRow && obstacleGrid[row][0] == 0; ++row) dp[row][0] = 1; //初始化第一列
    for(int row  = 1; row < nRow; ++row)
        for(int col = 1; col < nCol; ++col) {
            if(obstacleGrid[row][col]==1) continue;
            dp[row][col] = dp[row][col-1] + dp[row-1][col];
        }
    return dp[nRow-1][nCol-1];
}

int main (int argc, char* argv[])
{
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int ret = uniquePathsWithObstacles(obstacleGrid);
    cout << "Result: " << ret << endl;
    
    return 0;
}