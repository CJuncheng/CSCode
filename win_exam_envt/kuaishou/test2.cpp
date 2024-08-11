#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getMaxSum(const vector<int>& vecs){
    const int n = vecs.size();
    vector<int> dp(n);
    vector<int> idxs;

    dp[0] = vecs[0];
    dp[1] = max(vecs[0], vecs[1]);

    if(dp[1] == vecs[1]) idxs.push_back(1);

    for(int i = 2; i < n; ++i){
        dp[i] = max(dp[i-2]+vecs[i], dp[i-1]);
        if(dp[i] == dp[i-2]+vecs[i]) idxs.push_back(i);
    }
    return idxs;
}

int main() {
    vector<int> vecs = {1, 2, 3, 4, 5};
    vector<int> idxs = getMaxSum(vecs);
    int sum = 0;
    for(int i = 0; i < (int)idxs.size(); ++i){
        cout << idxs[i] << " ";
        sum += vecs[idxs[i]];
    }
    cout << endl;
    cout << sum << endl;
    
    
}