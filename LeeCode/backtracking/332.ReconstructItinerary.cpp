#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;

// unordered_map<出发机场, map<到达机场, 航班次数>> targets
unordered_map<string, map<string, int>> targets;
bool backtracking(int tichetNum, vector<string>& res)
{
    if(res.size() == tichetNum + 1) return true;
    for(pair<const string, int> & target : targets[res[res.size()-1]]){
        if(target.second > 0) {
            res.push_back(target.first);
            --target.second;
            if(backtracking(tichetNum, res)) return true;
            res.pop_back();
            ++target.second;
        }
    }
    return false;
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> res;
    for(const vector<string> & sVec : tickets) 
        ++targets[sVec[0]][sVec[1]];
    res.push_back("JFK");
    backtracking(tickets.size(), res);
    return res;
}


// unordered_map<出发机场, map<到达机场, 航班次数>> targets
bool backtracking(int ticketNum, vector<string>& result) {
    if (result.size() == ticketNum + 1) {
        return true;
    }
    for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
        if (target.second > 0 ) { // 记录到达机场是否飞过了
            result.push_back(target.first);
            target.second--;
            if (backtracking(ticketNum, result)) return true;
            result.pop_back();
            target.second++;
        }
    }
    return false;
}
