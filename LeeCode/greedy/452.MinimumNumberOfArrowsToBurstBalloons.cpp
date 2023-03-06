#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool compare(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), compare);
    const int len = points.size();
    if(!len) return 0;
    int res = 1;
    
    for(int i = 1; i < len; ++i) {
        if(points[i-1][1] < points[i][0]) ++res;
        else points[i][1] = min(points[i-1][1], points[i][1]);
    }
    return res;
}

int main (int argc, char* argv[])
{ 
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    int ret = findMinArrowShots(points);
    cout << "Result: " << ret << endl;

    return 0;
}