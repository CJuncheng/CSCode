#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

//计算 RPN
int evalRPN(vector<string>& tokens) {
    stack<long> st;
    const size_t len = tokens.size();
    for(size_t i = 0; i < len; ++i) {
        if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
            long tmp1 = st.top(); st.pop();
            long tmp2 = st.top(); st.pop();
            switch(tokens[i][0]) {
                case '+': st.push(tmp2+tmp1); break;
                case '-': st.push(tmp2-tmp1); break;
                case '*': st.push(tmp2*tmp1); break;
                case '/': st.push(tmp2/tmp1); break;
                default: break;
            }
        }
        else st.push(stoi(tokens[i]));
    }
    return st.top(); //只剩下一个元素
}

int main (int argc, char* argv[])
{
    vector<string> sVec = {"-128","-128","*","-128","*","-128","*","8","*","-1","*"};
    int ret = evalRPN(sVec);
    cout << ret << endl;   // 返回 1
    return 0;
}