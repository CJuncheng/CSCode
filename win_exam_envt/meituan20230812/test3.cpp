#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    long prefix_sum = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            cin >> nums[i][j];
            prefix_sum += nums[i][j];
        }
    vector<long> row_profix_sum, col_profix_sum;
    int tmp = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j) tmp += nums[i][j];
        row_profix_sum.push_back(tmp);
    }
    tmp = 0;
    for(int j = 0; j < m; ++j){
        for(int i = 0; i < n; ++i) tmp += nums[i][j];
        col_profix_sum.push_back(tmp);
    }
    long res = INT_MAX;
    for(int i = 0; i < (int)row_profix_sum.size(); ++i)
        res = min(res, abs((prefix_sum-row_profix_sum[i])-row_profix_sum[i]));
    for(int i = 0; i < (int)col_profix_sum.size(); ++i)
        res = min(res, abs((prefix_sum-col_profix_sum[i])-col_profix_sum[i]));
    cout << res << endl;

    return 0;
}