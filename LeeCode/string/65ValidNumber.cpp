#include <iostream>
#include <cstdlib>
#include <string> 

using namespace std;
/* strtod库函数法
bool isNumber(const char* s)
{
    char* endptr;
    strtod(s, &endptr);
    
    if(endptr==s) return false;
    for(;*endptr; ++endptr) {
        if(!isspace(*endptr)) return false;
    }
    return true;
}

bool isNumber(string s) {
    size_t count = 0;
    for(size_t i = 0; i < s.size(); ++i)
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||s[i]=='-'||s[i]=='+')
            ++count;
    if(count==s.size()) return false;
    return isNumber(s.c_str());
}
*/
// 有限状态机， 不太理解

bool isNumber(const string& s) {
    enum InputType {
        INVALID,
        // 0
        SPACE,
        // 1
        SIGN,
        // 2
        DIGIT,
        // 3
        DOT,
        // 4
        EXPONENT,
        // 5
        NUM_INPUTS
        // 6
    };
    const int transitionTable[][NUM_INPUTS] = {
        -1, 0, 3, 1, 2, -1, // next states for state 0
        -1, 8, -1, 1, 4, 5,
        // next states for state 1
        -1, -1, -1, 4, -1, -1,
        // next states for state 2
        -1, -1, -1, 1, 2, -1,
        // next states for state 3
        -1, 8, -1, 4, -1, 5,
        // next states for state 4
        -1, -1, 6, 7, -1, -1,
        // next states for state 5
        -1, -1, -1, 7, -1, -1,
        // next states for state 6
        -1, 8, -1, 7, -1, -1,
        // next states for state 7
        -1, 8, -1, -1, -1, -1,
        // next states for state 8
    };
    int state = 0;
    for (auto ch : s) {
        InputType inputType = INVALID;
        if (isspace(ch))
        inputType = SPACE;
        else if (ch == '+' || ch == '-')
        inputType = SIGN;
        else if (isdigit(ch))
        inputType = DIGIT;
        else if (ch == '.')
        inputType = DOT;
        else if (ch == 'e' || ch == 'E')
        inputType = EXPONENT;
        // Get next state from current state and input symbol
        state = transitionTable[state][inputType];
        // Invalid input
        if (state == -1) return false;
    }
    // If the current state belongs to one of the accepting (final) states,
    // then the number is valid
    return state == 1 || state == 4 || state == 7 || state == 8;
}



int main (int argc, char* argv[])
{
    const string str = "inf";
    
    bool ret = isNumber(str);
    std::cout << ret << std::endl;
    return 0;
}