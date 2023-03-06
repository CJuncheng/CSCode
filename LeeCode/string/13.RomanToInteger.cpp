#include <iostream>
#include <vector>
#include <string>
using namespace std;

inline int map(const char& ch) {
    switch(ch) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default : return 0;
    }
}

int romanToInt(string s) {
    int sum = 0;
    int prev = map(s[0]);
    for(size_t i = 1; i < s.size(); ++i) {
        int cur = map(s[i]);
        if(prev < cur) sum -= prev;
        else sum+=prev;
        prev = cur;
    } 
    sum+=prev;
    return sum;
}

int main (int argc, char* argv[])
{
    const string str = "IX";
    int ret = romanToInt(str);
    std::cout << ret << std::endl;
    return 0;
}