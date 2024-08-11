// 字符串，两个字符串 s(长), p(短), 至少去掉 s 中多少字符， 使得 p 是 s 的子串

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int removeNChars(string& S, string& P){
    const int n1 = S.size();
    const int n2 = P.size();
    if(n1 < n2) return -1; 
    
    vector<int> idxs;
    for(int i = 0; i < n1; ++i)
        if(S[i] == P[0]) idxs.push_back(i);
        
    int res = 0;
    for(int k = 0; k < (int)idxs.size(); ++k){
        int start = 0, end = 0;
        int j = 0;
        for(int i = idxs[k]; i < n1; ++i){
            if(S[i] == P[j]) {
                if(j == 0) start = i;
                if(j == n2-1) end = i;
                ++j;
            }
        }
        if(j==n2) {
            res = min(res, end+1-start - n2);
        }
    }
    return res;
}


int main (int argc, char* argv[]){
    string S = "abacdabd";
    string P = "abd";
    int ret = removeNChars(S, P);
    cout << ret << endl;
    return 0;
}