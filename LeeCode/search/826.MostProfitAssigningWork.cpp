#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
    static bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs){
        return lhs.first < rhs.first;
    }
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int len = difficulty.size();
        vector<pair<int, int>> jobs(len);
        for(int i = 0; i < len; ++i) 
            jobs[i] = make_pair(difficulty[i], profit[i]);
        sort(jobs.begin(), jobs.end(), cmp);
        sort(worker.begin(), worker.end());

        int res = 0, idx = 0, best = 0;
        for(int& level : worker){
            
            while(idx<len&&level>=jobs[idx].first)
                best = max(best, jobs[idx++].second);
            res += best;
        }
        return res;


       
    }
};