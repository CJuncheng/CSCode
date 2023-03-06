#include <iostream>
#include <vector>

using namespace std;

vector<string> res;
string path;

inline
bool isValid(const string& str, int start, int last)
{   
    if(last < start) return false;
    if(str[start] == '0' && start != last) return false;
    for(int num=0, i = start; i <= last; ++i){
        num = num*10+str[i] - '0';
        if(num>255) return false;
    }
    return true;
}

void backtracking(const string& str, int start, int pointCount)
{
    if(pointCount==3) {
        if(isValid(str, start, str.size()-1)) 
            res.push_back(path+str.substr(start, str.size()));
        return;
    }
    for(int last = start; last < (int)str.size(); ++last){
        if(last-start>=3) break; // 剪枝
        if((int)str.size()-1-last > 3*(4-pointCount)) continue; //剪枝
        if(isValid(str, start, last)){
            string substr = str.substr(start, last-start+1)+ '.';
            path+=substr;
            ++pointCount;
            backtracking(str, last+1, pointCount);
            --pointCount; //回溯
            path.erase(path.size()-substr.size(), substr.size()); //回溯
        } else continue;
    }
}

vector<string> restoreIpAddresses(string s) {
    if(s.size()< 4 || s.size() > 12) return res;
    for(auto it = s.begin(); it != s.end(); ++it) // 保证数字是合法的
        if(*it < '0' || *it > '9') return res; 
    backtracking(s, 0, 0);
    return res;
}


int main (int argc, char* argv[])
{
    string str = "25525511135";
    vector<string> ret = restoreIpAddresses(str);
    for (auto it = ret.begin(); it != ret.end(); ++it)
        std::cout << *it << std::endl;
    return 0;
}