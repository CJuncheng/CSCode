#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
    size_t len = s.size();
    if (len&0x1) return false; // 如果s的长度为奇数，一定不符合要求
    stack<char> S;

    for(size_t i = 0; i < len; ++i){
        switch(s[i]) {
            case '(': case '[': case '{': S.push ( s[i] ); break;
            case ')': if ( S.empty() ||'(' != S.top() ) return false; S.pop(); break;
            case ']': if ( S.empty() ||'[' != S.top() ) return false; S.pop();  break;
            case '}': if ( S.empty() ||'{' != S.top() ) return false; S.pop();break;
            default: break; //非括号字符一徇忽略
        }
    }
    return S.empty();
}

int main (int argc, char* argv[])
{
    string str ="(){()[]}";
    bool ret = isValid(str);
    cout << ret << endl;   // 返回 1
    return 0;
}