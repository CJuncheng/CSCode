#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool compare(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);
    const int len = intervals.size();
    if(!len) return 0;
    int count = 1;
    int end = intervals[0][1];
    for(int i = 1; i < len; ++i) {
        if(end <= intervals[i][0]) {
            ++count;
            end = intervals[i][1];
        }
    }
    return len - count;
}

int main (int argc, char* argv[])
{ 
    vector<vector<int>> intervals = {{1,2},{1,2},{1,2}};
    int ret = eraseOverlapIntervals(intervals);
    cout << "Result: " << ret << endl;

    return 0;
}



