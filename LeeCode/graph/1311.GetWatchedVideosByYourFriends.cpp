#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    struct CompareLess{ //最小堆， 队列中元素按从小到大排序
        bool operator()(const pair<string, int>& lhs, const pair<string, int>& rhs){
            return (lhs.second > rhs.second) || (lhs.second == rhs.second&&lhs.first > rhs.first);
        }
    };
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        const int len = friends.size();
        vector<bool> used(len);
        queue<int> que;
        que.push(id);
        used[id] = true;
        
        for(int i = 0; i < level; ++i){
            int span = que.size();
            for(int j = 0; j < span; ++j){
                int u = que.front(); que.pop();
                for(int& v : friends[u])
                    if(!used[v]) {
                        que.push(v);used[v] = true;
                    }
            }
        }
    
        unordered_map<string, int> freq;
        while(!que.empty()){
            int u = que.front(); que.pop();
            for(auto& watched : watchedVideos[u])
                ++freq[watched];
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, CompareLess> priQue(freq.begin(), freq.end());
        vector<string> res;
        while(!priQue.empty())
        {
            auto u = priQue.top(); priQue.pop();
            res.push_back(u.first);
        }
   
        return res;
    }
};