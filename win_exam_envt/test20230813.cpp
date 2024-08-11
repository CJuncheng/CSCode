#include <iostream>
#include <vector>
#include <string>
using namespace std;

string FindLongestlncreasingDigitsSubstr(const string& s){
    const int n = s.size(); 
    int sublen = -1;
    string res;
    for(int i = 0; i < n-1; ++i){
        if(!isdigit(s[i])) continue;
        int cnt = 1;
        int start = i;
        while (i < n-1 && isdigit(s[i+1]) && isdigit(s[i]) && s[i+1] > s[i]) {
            ++cnt;  ++i;
        }
        if(cnt > sublen){
            sublen = cnt;
            res = s.substr(start, sublen);
        }
    }
    return res;
}

int main(int argc, char* argv[]){
    string s = "abc126def6789";
    string ret = FindLongestlncreasingDigitsSubstr(s);
    cout << ret << endl;
    return 0;
}