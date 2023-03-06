#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

static bool compare(const vector<int>& a, const vector<int>& b)
{
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), compare);
    const int len = people.size();
    list<vector<int>> que;
    for(int i = 0; i < len; ++i) {
        int position = people[i][1];
        auto it = que.begin();
        while(position--) ++it;
        que.insert(it, people[i]);
    }
    return vector<vector<int>>(que.begin(), que.end());
}






