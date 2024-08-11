#include <iostream>
#include <vector>
#include <map>
#include <cctype> // tolower()
#include <utility> // pair
#include <unordered_map>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <initializer_list>
#include <cstring>
#include <algorithm>
#include <functional>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int m = 10; // 服务节点个数
    int n = 120; // rsTimes 的长度
    int start = 1; //起点
    vector<vector<pair<int, int>>> adj(m);
    vector<bool> vst(m, false);
    vector<vector<int>> rsTimes = {{1, 2, 10}, {1, 2, 11}, {1, 3, 12}};
    for(auto& rsTime : rsTimes) {
        adj[rsTime[0]].push_back(make_pair(rsTime[1], rsTime[2]));
    }
    int min_time = INT_MAX;
    int service_cnt = 0;
    function<void(int, int)> backTracking = [&](int x, int sum){
        if(adj[x].empty()) {
            ++service_cnt;
            min_time = min(min_time, sum);
            return;
        }
        vst[x] = true;
        for(int i = 0; i < adj[x].size(); ++i){
            sum += adj[x][i].second;
            if(vst[adj[x][i].first]==false)
                backTracking(adj[x][i].first, sum);
            sum -= adj[x][i].second;
        }
        vst[x] = false;
    };
    cout << service_cnt << " " << min_time << endl;   
    return 0;
}
