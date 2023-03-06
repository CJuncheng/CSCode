#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int candy(vector<int>& ratings) {
    const int n = ratings.size();
    vector<int> result(n, 1);
    // 两次贪心
    // 右孩子比左孩子多（需要从左向右）
    for(int i = 1; i < n; ++i) 
        if(ratings[i] > ratings[i-1])
            result[i] = result[i-1] + 1;
    // 左孩子比右孩子多（需要从右向左）
    for(int i = n - 2; i >=0; --i)
        if(ratings[i] > ratings[i+1]) 
            result[i] = max(result[i], result[i+1] + 1);
    int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += result[i];
    return sum;
}

int main (int argc, char* argv[])
{
    vector<int> ratings = {1, 2, 2, 5, 4, 3, 2};
    int ret = candy(ratings);
    cout << ret << endl;

    return 0;
}