#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

struct CompareMore{ //最大堆， 队列中元素按从大到小排序
    bool operator()(const pair<char, int>& lhs, const pair<char, int>& rhs){
        return lhs.second < rhs.second;
    }
};
string frequencySort(string s) {
    unordered_map<char, int> umap;
    for(auto c : s) ++umap[c];
    priority_queue<pair<char, int>, vector<pair<char, int>>, CompareMore> priQue(umap.begin(), umap.end());
    s.clear();
    while(!priQue.empty()){
        auto tmp = priQue.top();
        s += string(tmp.second, tmp.first);
        priQue.pop();
    }
    return s;
}

int main (int argc, char* argv[])
{
    string str = "aaacccddddd";
    string ret = frequencySort(str);
    std::cout << ret << std::endl;

    return 0;
}