#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
//回溯
bool backtracking(const string& s, const unordered_set<string>& uset, vector<bool>& memory, int start)
{
    if(start >= (int)s.size())
        return true;
    if(!memory[start]) return false; // 记忆剪枝

    for(int i = start; i < (int)s.size(); ++i){
        string subStr = s.substr(start, i-start+1);
        if(uset.find(subStr) != uset.end() && backtracking(s, uset, memory, i+1)) 
            return true; 
    }
    memory[start] = false; // 记录以start开始的子串是不可以被拆分的
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> uset(wordDict.begin(), wordDict.end());
    vector<bool> memory(s.size(), true); // 初始化，表示任意 memory[i]开始的字符串可以拆分
    return backtracking(s, uset, memory, 0);
}
*/

/* 完全背包方法， 数学定理方法更高效
 * dp[j]：字符串长度为i的话，dp[i]为true，表示可以拆分为一个或多个在字典中出现的单词
*/
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> uset(wordDict.begin(), wordDict.end());
    const int len = s.size()+1;
    vector<bool> dp(len+1, false);
    dp[0] = true;
    for(int j = 1; j <= len; ++j)
        for(int i = 0; i < j; ++i) {
            string subStr = s.substr(i, j-1-i+1);
            if(uset.find(subStr) != uset.end() && dp[i])
                dp[j] = true;
        }
    return dp[len];
}



int main (int argc, char* argv[])
{
    string s = "catsanddog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};
    bool ret = wordBreak(s, wordDict);
    cout << "Result: " << ret << endl;
    return 0;
}