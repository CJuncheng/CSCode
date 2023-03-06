#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        unordered_map<int, vector<int>> umap;
        for(int i = 0; i < prerequisites.size(); ++i){
            ++inDegree[prerequisites[i][0]];
            umap[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> que;
        for(int i = 0; i < numCourses; ++i){
            if(inDegree[i]==0) que.push(i); //所有入度为0的课入列
        }
        vector<int> res;
        while(que.size()){
            res.push_back(que.front());
            vector<int> nextCourses = umap[que.front()]; que.pop();
            for(int i = 0; i < nextCourses.size(); ++i){
                --inDegree[nextCourses[i]];
                if(inDegree[nextCourses[i]]==0) que.push(nextCourses[i]);
            }
        }
        return res.size()==numCourses ? res : vector<int>{};
    }
};