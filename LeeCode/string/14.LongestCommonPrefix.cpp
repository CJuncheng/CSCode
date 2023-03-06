#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    /*
    if(strs.empty()) return "";
    const int n = strs.size();
    size_t minLen = strs[0].size();
    for(int i = 0; i < n; ++i) 
        if(strs[i].size() < minLen) minLen = strs[i].size();
    size_t j = 0;
    for(; j < minLen; ++j){
        bool flag = false;
        for(int i = 1; i < n; ++i) 
            if(strs[0][j]!=strs[i][j]) { flag = true; break; }
        if(flag) break;
    }
    return strs[0].substr(0, j);
    */
    if(strs.empty()) return "";
    const int n = strs.size();
    const int len = strs[0].size();
    for(int j = 0; j < len; ++j){
        for(int i = 1; i < n; ++i) 
            if(strs[0][j]!=strs[i][j]) return strs[0].substr(0, j);
    }
    return strs[0];
}

int main (int argc, char* argv[])
{
    vector<string> strs = {"flower", "flow", "flight"};
    string ret = longestCommonPrefix(strs);
    std::cout << ret << std::endl;
    return 0;
}