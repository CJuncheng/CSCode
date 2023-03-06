#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
/*
// 1.
struct {
    bool operator()(const vector<int>& vec1, const vector<int>& vec2){
        return pow(vec1[0], 2)+pow(vec1[1], 2) < pow(vec2[0], 2)+pow(vec2[1], 2);
    }
} compareLess;
*/

// 2.
bool compare(const vector<int>& vec1, const vector<int>& vec2){
    return pow(vec1[0], 2)+pow(vec1[1], 2)< pow(vec2[0], 2)+pow(vec2[1], 2);
}

/*
// 3.
[](const vector<int>& vec1, const vector<int>& vec2) {
    return pow(vec1[0], 2)+pow(vec1[1], 2)< pow(vec2[0], 2)+pow(vec2[1], 2);
}
*/
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    sort(points.begin(), points.end(),compare);
    return vector<vector<int>>(points.begin(), points.begin()+k);
}
