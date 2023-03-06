
#include <iostream>
#include <string>
using namespace std;

inline
string discriblePrevItem(const string& s)
{
    const int len = s.size();
    string result;
    if(len == 1)  return "11";
    for(int i = 1; i <= len; ++i) {
        int count = 1;
        while(i<len&&s[i-1]==s[i]){
            ++count; ++i;
        }

        result += to_string(count)+ s.substr(i-1, 1);
    }
    return result;
}

string countAndSay(int n) {
    string result = "1";
    for(int i = 1; i < n; ++i)
        result = discriblePrevItem(result);
    return result;
}

int main (int argc, char* argv[])
{
    string ret = countAndSay(5);
    std::cout << ret << std::endl;

    return 0;
}