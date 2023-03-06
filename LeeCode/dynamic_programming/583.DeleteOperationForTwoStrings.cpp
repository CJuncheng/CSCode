#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* 动态规划
 * dp[i][j] ：长度为[0, i - 1]的字符串 word1 与长度为[0, j - 1]的字符串 word2 的最长公共子序列为dp[i][j]
 *  dp[i][0] 和 dp[0][j]其实都是没有意义的！均为0
 */

int minDistance(string word1, string word2) {
    const int lenA = word1.size(), lenB = word2.size();
    vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1));
    for(int i = 1; i <= lenA; ++i) {
        for(int j = 1; j <= lenB; ++j){
            if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1] +1;
            else  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return lenA - dp[lenA][lenB] + lenB - dp[lenA][lenB];
}

/* 动态规划
 * dp[i][j]：以i-1为结尾的字符串word1，和以j-1位结尾的字符串word2，想要达到相等，所需要删除元素的最少次数。
 */

int minDistance(string word1, string word2) {
    const int lenA = word1.size(), lenB = word2.size();
    vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1));
    for(int i = 0; i <= lenA; ++i) dp[i][0] = i;
    for(int j = 1; j <= lenB; ++j) dp[0][j] = j;
    for(int i = 1; i <= lenA; ++i) {
        for(int j = 1; j <= lenB; ++j){
            if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else  dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
        }
    }
    return dp[lenA][lenB];
}



int main (int argc, char* argv[])
{
    string word1 =  "sea";
    string word2 = "eat";
    int ret = minDistance(word1, word2);
    cout << "Result: " << ret << endl;
    
    return 0;
}