#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 双指针
bool isSubsequence(string s, string t) {
    const int lenS = s.size(), lenT = t.size();
    int i = 0, j = 0;
    while(i < lenS && j < lenT){
        if(s[i]==t[j]) ++i;
        ++j;
    }
    if(i == lenS) return true;
    return false;
}
