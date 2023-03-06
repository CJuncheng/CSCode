/*
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {   
    const size_t n = gas.size();
    if (n < 2) {
        if(gas[0]>=cost[0]) return 0;
        return -1; 
    }
    for (size_t i = 0; i < n; ++i) { //一次从第i个加油站出发
        if(gas[i] <= cost[i]) continue;
        int remain = gas[i];
        size_t temp = 0;
        for(size_t j = i+1; j < i + n; ++j) {
            size_t cur = j % n, prev=0;
            temp = j;
            if(cur == 0) prev = n-1;
            else prev = cur - 1;
            remain += gas[cur] - cost[prev];
            if (remain <= cost[cur]) break;
        }
        if (temp == i+n-1 && remain>=cost[temp%n]) return (int)i;
    }
    return -1;
}
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int cur = 0, remain = 0, start = 0;// remain 是总剩余
    const int len = gas.size();
    for(int i = 0; i < len; ++i) {
        cur += gas[i] - cost[i];
        remain += gas[i] - cost[i];
        if(cur < 0) {
            cur = 0;
            start=i+1;
        }
    }
    return remain >= 0 ? start : -1;
}