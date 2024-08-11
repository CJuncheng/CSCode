#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


int solution(vector<vector<int>>& intervals){
    
    const int n = intervals.size();
    sort(intervals.begin(), intervals.end(), [](vector<int>& lhs, vector<int>& rhs){
        if(lhs[0]==rhs[0]) return lhs[1] < rhs[1];
        return lhs[0] < rhs[0];
    });
    
    int res = 0;
    int l = intervals[0][0], r = intervals[0][1];
    for(int i = 1; i < n; ++i){
        if(r >= intervals[i][1] ){
            ++res;
            l = intervals[i][0];
            r = intervals[i][1];
        } else if(r > intervals[i][0] ) ++res;
        else {
            l = intervals[i][0];
            r = intervals[i][1];
        }
    }
    return ++res;
}

int main(int argc, char* argv[]){
       
    vector<vector<int>> intervals = {{1, 2}, {2, 3}};
    int ret = solution(intervals);
    cout << ret << endl;
    return 0;
}