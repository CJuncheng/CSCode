#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;


vector<string> res;
string path;
// 使用回溯算法
void backtracking(const string& s, const unordered_set<string>& uset, int start)
{
    if(start >= (int)s.size())
        res.push_back(path.substr(0, path.size()-1));
    for(int i = start; i < (int)s.size(); ++i){
        string subStr = s.substr(start, i-start+1);
        if(uset.find(subStr) != uset.end()) {
            path += subStr + ' ';
            backtracking(s, uset, i+1);
            path.erase(path.size()-subStr.size()-1, subStr.size()+1);  
        }
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> uset(wordDict.begin(), wordDict.end());
    backtracking(s, uset, 0);
    return res;
}
