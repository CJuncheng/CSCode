#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<int> findRightInterval(vector<vector<int>>& intervals) {
    const int len = intervals.size();
    vector<int> res(len, -1);
    map<int, int> map;
    for(int i = 0; i < len; ++i) map[intervals[i][0]] = i;
    for(int i = 0; i < len; ++i) {
        auto it = map.lower_bound(intervals[i][1]);
        if(it!=map.end()) res[i] = it->second;
    }
    return res;
}