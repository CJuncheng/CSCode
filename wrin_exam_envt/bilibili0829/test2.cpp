class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s1 string字符串
     * @param s2 string字符串
     * @return int整型
     */
    int minDeleteSum(string s1, string s2) {
        // write code here
        int m = s1.size();
        int n = s2.size();

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) 
            dp[i][0] = dp[i - 1][0] + s1[i - 1];

        for (int j = 1; j <= n; j++) 
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};