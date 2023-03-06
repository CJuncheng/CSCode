#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

/*
    https://leetcode.cn/problems/find-the-town-judge/solution/ji-lu-yi-xia-mei-xue-guo-tu-kan-bie-ren-i7zub/
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       
        vector<int> trustValues(n+1);
        for(auto& vec : trust){
            --trustValues[vec[0]];
            ++trustValues[vec[1]];
        }
        for(int i = 1; i<=n; ++i)
            if(trustValues[i]==n-1) return i;
        return -1;
    }
};