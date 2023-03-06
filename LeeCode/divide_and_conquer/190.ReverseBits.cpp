#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;   

class Solution {
public:
/*
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16); //低16位与高16位交换
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8); //每16位中低8位和高8位交换; 1111是f
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4); //每8位中低4位和高4位交换;
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2); //每4位中低2位和高2位交换; 1100是c,0011是3
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1); //每2位中低1位和高1位交换; 1010是a,0101是5
        return n;
    }
*/
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i = 0; i < 32; ++i){
            res = (res<<1)|(n&0x1);
            n>>=1;
        }
        return res;
    }
};