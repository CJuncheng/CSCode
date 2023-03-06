#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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

int main (int argc, char* argv[])
{
    vector<int> gas =  {1,2,3,4,5,5,70};//{1,2,3,4,5};  {1,2,3,4,5,5,70}
    vector<int> cost = {2,3,4,3,9,6,2}; //{3,4,5,1,2}; {2,3,4,3,9,6,2}
    int ret = canCompleteCircuit(gas, cost);
    std::cout << "ret: " << ret << std::endl;

    return 0;
}