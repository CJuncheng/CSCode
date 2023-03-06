#include <iostream>
#include <string>
using namespace std;

class Solution {
    inline void invert(char& c){
        c=='1' ? c='0' : c='1'; 
    }
public:
    int minOperations(string s) {
        const int len = s.size();
        //第一位不变
        int count = 0;
        for(int i = 1; i <len; ++i){
            if(s[i-1]==s[i]) { 
                ++count;
                invert(s[i]);
            }
        } 
        return min(count, len-count);
    }
};



