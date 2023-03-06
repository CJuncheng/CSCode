#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 回文子序列： 不连续， 回文子串连续

/* 动态规划法
 * 布dp[i][j]：字符串s在[i, j]范围内最长的回文子序列的长度为dp[i][j]。
 * 如果s[i]与s[j]相同，那么dp[i][j] = dp[i + 1][j - 1] + 2;
 * 如果s[i]与s[j]不相同，加入s[j]的回文子序列长度为 dp[i + 1][j]。
 *                      加入s[i]的回文子序列长度为 dp[i][j - 1]。
 * 
 */
/*
int longestPalindromeSubseq(string s) {
    const int len = s.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for(int i = 0; i < len; ++i) dp[i][i] = 1;
    for(int i = len-1; i >=0; --i)
        for(int j = i+1; j<len; ++j) {
            if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1] + 2;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    return dp[0][len-1];
}
*/

int longestPalindromeSubseq(string s) {
    const int len = s.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for(int i = len-1; i >=0; --i)
        for(int j = i; j<len; ++j) {
            if(i==j) dp[i][j] = 1;
            else if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1] + 2;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    return dp[0][len-1];
}
int main (int argc, char* argv[])
{
    string str =  "bbbab";
    int ret = longestPalindromeSubseq(str);
    cout << "Result: " << ret << endl;
    
    return 0;
}