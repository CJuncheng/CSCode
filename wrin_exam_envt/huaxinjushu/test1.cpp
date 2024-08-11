//给定一些平面上的点，请你找到穿过点最多的直线。

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> points;
    for(int i= 0; i < n; ++i){
        int x, y; cin >> x >> y;
        points.emplace_back(vector<int>{x, y});
    }
    int res = 0;
    float slope = 0.0, intercept = 0.0;
    for(int i = 0; i < n-2; ++i)
        for(int j = i+1; j < n-1; ++j){
            int cnt = 2;
            int x1 = points[i][0]-points[j][0];
            int y1 = points[i][1]-points[j][1];
            for(int k = j+1; k < n; ++k){
                int x2 = points[i][0]-points[k][0];
                int y2 = points[i][1]-points[k][1];
                if(x1*y2 == x2*y1) ++cnt;
            }
            if(cnt > res){
                slope = y1*1.0/x1;
                intercept = points[i][1]*1.0-slope*points[i][0]*1.0;
            }
        }
    cout << slope << " " << intercept << endl;

}
// 64 位输出请用 printf("%lld")