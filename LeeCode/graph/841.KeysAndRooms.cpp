#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:

    void dfs(const vector<vector<int>>& rooms, int idx, vector<bool>& visited){
        visited[idx]=true;
        for(int i : rooms[idx])
            if(!visited[i]) dfs(rooms, i, visited);
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        dfs(rooms, 0, visited);
        for(int i : visited)
            if(!i) return false;
        return true;
    }
};