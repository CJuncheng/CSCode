#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int ans = 0;
    const int len = s.size();
    for(int i = 0; i < len; ++i) {
        if(s[i]=='(') st.push(i);
        else {
            st.pop();
            if(st.empty()) st.push(i); //最后一个没有被匹配的右括号的下标
            else ans = max(ans, i - st.top());
        }
    }
    return ans;
}

int main (int argc, char* argv[])
{
    string str ="())";
    int ret = longestValidParentheses(str);

    cout << ret << endl;   // 返回 1
    return 0;
}