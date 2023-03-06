#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;   
   
const int base = 1337;

// 计算 a 的 k 次方然后与 base 求模的结果
int myPow(int a, int k)
{
    a %= base;
    int res = 1;
    for(int i = 0; i< k; ++i){
        res *= a; res %= base;
    }
    return res;
}

int superPow(int a, vector<int>& b) {
    if (b.empty()) return 1;
    int last = b.back();
    b.pop_back();

    int part1 = myPow(a, last);
    int part2 = myPow(superPow(a, b), 10);
    return part1*part2%base;
}