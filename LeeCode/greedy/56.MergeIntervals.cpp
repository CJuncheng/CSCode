#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool compare(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    const int len = intervals.size();
    sort(intervals.begin(), intervals.end(), compare);
    vector<vector<int>> res;
    if(!len) return res;
    res.push_back(intervals[0]);
    for(int i = 1; i < len; ++i) {
        if(res.back()[1] >= intervals[i][0]) {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        } else {
            res.push_back(intervals[i]);
        }
    }
    return res;
}

int main (int argc, char* argv[])
{ 
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> ret = merge(intervals);
    cout << "Result: "  << endl;
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
            std::cout << *it2 << " " ;
        std::cout << std::endl;
   }

    return 0;
}
