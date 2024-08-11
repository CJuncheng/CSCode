#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main(int argc, char* argv[]){
    int n; cin >> n;
    vector<int> heights(n);
    for(int i = 0; i < n; ++i) cin >> heights[i];
    sort(heights.begin(), heights.end());
    
    deque<int> dq;
    for (int i = 0; i < n; ++i){
        int num = heights.back();
        heights.pop_back();
        if(i & 1) dq.push_back(num);
        else dq.push_front(num);
    }
    int res = dq.front() - dq.back();
    int num1 = dq.front(), num2;
    for (int i = 1; i < n; ++i){
        int num1 = dq.front();
        dq.pop_front();
        int num2 = dq.front();
        res = max(abs(num1 - num2), res);
    }
    cout << res;
    return 0;
}