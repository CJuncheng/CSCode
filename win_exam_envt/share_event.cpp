#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int n, T, H;
    cin >> n >> T >> H;
    vector<int> t(n), h(n), a(n);
    for(int i = 0; i < n; ++i)
       cin >> t[i] >> h[i] >> a[i];
    
    // dp
    vector<vector<int>> dp(T + 1, vector<int>(H + 1, 0));
    for (int k = 0; k < n; k++) {
        for (int i = T; i >= t[k]; i--) {
            for (int j = H; j >= h[k]; j--) {
                dp[i][j] = max(dp[i][j], dp[i - t[k]][j - h[k]] + a[k]);
            }
        }
    }

    return dp[T][H];  
}
