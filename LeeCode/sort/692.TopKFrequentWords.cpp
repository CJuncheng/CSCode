#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <unordered_map>
using namespace std;

struct CompareMore{ //最大堆， 队列中元素按从大到小排序
    bool operator()(const pair<string, int>& lhs, const pair<string, int>& rhs){
        if(lhs.second==rhs.second) return lhs.first>rhs.first;
        else return lhs.second < rhs.second;
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> umap;
    for(auto & s : words) ++umap[s];
    priority_queue<pair<string, int>, vector<pair<string, int>>, CompareMore> priQue(umap.begin(), umap.end());
    vector<string> ret;
    while(k--){
        string tmp = priQue.top().first;
        ret.push_back(tmp);
        priQue.pop();
    }
    return ret;
}

int main(int argc, char* argv[])
{
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    vector<string> ret = topKFrequent(words, 3);
    for(auto i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << " ";
    cout << endl;
    return 0;
}
