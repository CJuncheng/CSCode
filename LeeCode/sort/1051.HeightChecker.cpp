#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int heightChecker(vector<int>& heights) {
    const int len = heights.size();
    vector<int> expected = heights;
    sort(expected.begin(), expected.end());
    int res = 0;
    for(int i = 0; i < len; ++i)
        if(expected[i] != heights[i]) ++res;
    return res;
}

int heightChecker(vector<int>& heights) {
    const int len = heights.size();
    int max = heights[0];
    for(int i = 1; i < len; ++i)
        if(heights[i]>max) max = heights[i]; // 找到[lo, hi)中最大值
    vector<int> expected(len), count(max+1);
    for(int i = 0; i < len; ++i)
        ++count[heights[i]];
    for(int j = 1; j < max + 1; ++j)
        count[j] += count[j-1];
    for(int i = len-1; i>=0; --i){
        expected[count[heights[i]]-1] = heights[i];
        --count[heights[i]];
    }
    int res = 0;
    for(int i = 0; i < len; ++i)
        if(expected[i] != heights[i]) ++res;
    return res; 
}
    