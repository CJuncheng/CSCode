#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* 动态规划
 * dp[i][j] ：长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]
 *  dp[i][0] 和 dp[0][j]其实都是没有意义的！均为0
 * 本题说是求绘制的最大连线数，其实就是求两个字符串的最长公共子序列的长度！
 *
 */

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    const int lenA = nums1.size(), lenB = nums2.size();
    vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1));
    for(int i = 1; i <= lenA; ++i) {
        for(int j = 1; j <= lenB; ++j){
            if(nums1[i-1] == nums2[j-1]) dp[i][j] = dp[i-1][j-1] +1;
            else  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[lenA][lenB];
}

int main (int argc, char* argv[])
{
    vector<int> nums1 =  {2,5,1,2,5};
    vector<int> nums2 = {10,5,2,1,5,2};
    int ret = maxUncrossedLines(nums1, nums2);
    cout << "Result: " << ret << endl;
    
    return 0;
}