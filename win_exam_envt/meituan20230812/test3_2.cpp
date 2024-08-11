#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
int n, m;
cin >> n >> m;
vector<vector<int>> cake(n, vector<int>(m));
vector<vector<int>> sum(n, vector<int>(m));
int total_sum = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cin >> cake[i][j];
        total_sum += cake[i][j];
        if (i > 0) {
            sum[i][j] = sum[i-1][j] + cake[i][j];
        } else {
            sum[i][j] = cake[i][j];
        }
    }
}

vector<vector<int>> dp(n, vector<int>(m));
dp[0][0] = total_sum - sum[n-1][m-1];

for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i-1][0] + abs(sum[i][0] - sum[i-1][0]);
}

for (int j = 1; j < m; j++) {
    dp[0][j] = dp[0][j-1] + abs(sum[0][j] - sum[0][j-1]);
}

for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
        dp[i][j] = min(dp[i-1][j] + abs(sum[i][j] - sum[i-1][j]), dp[i][j-1] + abs(sum[i][j] - sum[i][j-1]));
    }
}

cout << dp[n-1][m-1] << endl;

return 0;
}