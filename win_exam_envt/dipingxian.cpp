// 整数n 分解成至少两个数相加， 要求数的乘积最大， 输出最大乘积
// 3 = 2 + 1;

#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    int n = 10;
    vector<int> dp(n+1);
    if(n < 2) {
        cout << "Input value n is error!" << endl;
        return -1;
    }
    dp[2] = 1;
    for(int i = 3; i <= n; ++i)
        for(int j = 0; j <= i/2; ++j)
            dp[i] = max(dp[i], max(dp[i-j]*j, (i-j)*j));
    int res = dp[n];
    cout << "The max value is: " << res << endl;
    
    return 0;
}