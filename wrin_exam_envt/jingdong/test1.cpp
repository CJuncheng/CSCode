#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

int minOps(const string& str, int n){
    int res = INT_MAX;
    for(int i = 0; i < n; ++i){
        string str1 = str.substr(0, i), str2 = str.substr(i, n-i);
        string s = str2+str1;
        int cnt = i;
        for(int i = 0, j = s.size()-1; i<=j; ++i, --j)
            if(s[i] != s[j]) ++cnt;
        res = min(res, cnt);
    }
    return res;
}

int main() {
    int n; cin >> n;
    string str; cin >> str;
    int res = minOps(str, n);
    cout << res << endl;

}