#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* 动态规划
 * dp[i][j] ：dp[i][j] 表示以下标i-1为结尾的字符串word1，和以下标j-1为结尾的字符串word2，最近编辑距离为dp[i][j]。
 * if (word1[i - 1] == word2[j - 1])
 *      dp[i][j] = dp[i - 1][j - 1]
 * if (word1[i - 1] != word2[j - 1])
 *      dp[i][j] = dp[i - 1][j] + 1; word1删除一个元素，那么就是以下标i - 2为结尾的word1 与 j-1为结尾的word2的最近编辑距离再加上一个操作。
 *      dp[i][j] = dp[i - 1][j] + 1; word1添加一个元素，相当于word2删除一个元素，那么就是以下标i - 1为结尾的word1 与 j-2为结尾的word2的最近编辑距离 再加上一个操作。
 *      dp[i][j] = dp[i - 1][j - 1] + 1; 以下标i-2为结尾的word1 与 j-2为结尾的word2的最近编辑距离 加上一个替换元素的操作。
 */
int minDistance(string word1, string word2) {
    const int lenA = word1.size(), lenB = word2.size();
    vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1));
    for(int i = 0; i <= lenA; ++i) dp[i][0] = i;
    for(int j = 1; j <= lenB; ++j) dp[0][j] = j;
    for(int i = 1; i <= lenA; ++i) {
        for(int j = 1; j <= lenB; ++j){
            if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else  dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i - 1][j - 1]}) + 1;
        }
    }
    return dp[lenA][lenB];
}

int main (int argc, char* argv[])
{
    string word1 =  "intention";
    string word2 = "execution";
    int ret = minDistance(word1, word2);
    cout << "Result: " << ret << endl;
    
    return 0;
}