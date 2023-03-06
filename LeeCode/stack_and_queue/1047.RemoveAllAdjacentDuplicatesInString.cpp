#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string removeDuplicates(string S) {
    /*
    stack<char> st;
    for(auto &s : S)
        if(st.empty()||s!=st.top())
            st.push(s);
        else st.pop();
    string res;

    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
    */
   // 优化，字符串调用栈
   string res;
    for(auto &s : S)
        if(res.empty()||s!=res.back())
            res.push_back(s);
        else res.pop_back();
    return res;
}

    
int main (int argc, char* argv[])
{
    string str = "abbaca";
    string ret = removeDuplicates(str);
    cout << ret << endl;   // 返回 1
    return 0;
}