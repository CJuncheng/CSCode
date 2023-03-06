#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* 动态规划
 * dp[i][j] ：长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]
 *  dp[i][0] 和 dp[0][j]其实都是没有意义的！均为0
 * 如果text1[i - 1] 与 text2[j - 1]相同，那么找到了一个公共元素，所以dp[i][j] = dp[i - 1][j - 1] + 1;
 * 如果text1[i - 1] 与 text2[j - 1]不相同，那就看看text1[0, i - 2]与text2[0, j - 1]的最长公共子序列 
 *              和 text1[0, i - 1]与text2[0, j - 2]的最长公共子序列，取最大的。
 */
int longestCommonSubsequence(string text1, string text2) {
    const int lenA = text1.size(), lenB = text2.size();
    vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1));
    for(int i = 1; i <= lenA; ++i) {
        for(int j = 1; j <= lenB; ++j){
            if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] +1;
            else  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[lenA][lenB];
}


int main (int argc, char* argv[])
{
    string text1 =  "abcde";
    string text2 = "ace";
    int ret = longestCommonSubsequence(text1, text2);
    cout << "Result: " << ret << endl;
    
    return 0;
}