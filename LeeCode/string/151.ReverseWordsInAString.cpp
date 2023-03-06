
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

inline
void removeBlankSpace(string & s) {
    const size_t len = s.size();
    size_t slow = 0, fast = 0;
    while(fast<len && s[fast]==' ') ++fast;
    for(; fast<len; ++fast){
        if(fast-1>0&&s[fast-1]==s[fast]&&s[fast]==' ') continue;
        else s[slow++] = s[fast];
    }
    if(slow-1>0&&s[slow-1] == ' ') s.resize(slow-1);
    else s.resize(slow);
}

string reverseWords(string s) {
    if (s.size() ==0) return s;
    removeBlankSpace(s);
    std::cout << s << endl;
    reverse(s.begin(), s.end());
    for(auto it1 = s.begin(), it2 = s.begin(); it2 <= s.end(); ++it2){
        if(*it2 == ' '|| it2==s.end()) {
            reverse(it1, it2);
            it1 = it2+1;
        } 
    }
    return s;
}



int main (int argc, char* argv[])
{
    string str = "  hello world  ";
    string ret = reverseWords(str);

    std::cout << ret << endl;
   
    return 0;

}