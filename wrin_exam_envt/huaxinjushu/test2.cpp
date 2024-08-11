/*
已知个箱子的长、宽和高。请设计算法，计算将箱子堆起来的最大高
度(上面箱子的宽度和长度必须小于下面的箱子，且箱子不能旋转)。
*/

// https://www.nowcoder.com/questionTerminal/daaec37090484f4587d0e8f5b612cda1

#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(3001, 0);
int getMaxHeight(vector<int> w, vector<int> l, vector<int> h, int n) {
    int hi = n;
    while(0 < --hi){
        for(int i = 0; i < hi; ++i){
            if(w[i+1] >= w[i]){
                swap(w[i+1], w[i]);
                swap(l[i+1], l[i]);
                swap(h[i+1], h[i]);
            }
        }
    }

    dp[0] = h[0];
    int maxHeight = dp[0];
    for (int i = 1; i < n; i++) {
        int max_ = 0;
        for (int j = 0; j < i; j++)
            if (w[i] < w[j] && l[i] < l[j])
                max_ = max(max_, dp[j]);
        dp[i] = max_ + h[i];
        maxHeight = max(maxHeight, dp[i]);
    }
    return maxHeight;
}

int main() {
    int n;
    cin >> n;
    vector<int> L(n), W(n), H(n);
    for (int i = 0; i < n; ++i) {
        int l, w, h;
        cin >> l >> w >> h;
        L[i] = l, W[i] = w, H[i] = h;
    }
    int maxHeight = getMaxHeight(L, W, H, n);
    cout << maxHeight << endl;

    return 0;

}