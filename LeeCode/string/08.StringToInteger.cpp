#include <iostream>
#include <string>
using namespace std;

//INT_MAX (2147483647) or INT_MIN (-2147483648) 
int myAtoi(string s) {
    int i = 0, sign = 1;
    long num = 0; // 保证最后的 num 不溢出
    const int len = s.size();
    while(i<len&&s[i]==' ') ++i;
    if(s[i]=='+') ++i;
    else if (s[i]=='-') {++i; sign=-1;}
    for(; i<len; ++i){
        if(s[i]<'0'||s[i]>'9') break;
        if(num>INT_MAX/10 || (num==INT_MAX/10&&(s[i]-'0')>INT_MAX%10)) 
            return sign==-1 ? INT_MIN : INT_MAX;
        num = num*10 + s[i] - '0';
    }
    return num*sign;
}

int main (int argc, char* argv[])
{
    string str = "21474836460";
               // 2147483647
    int ret = myAtoi(str);
    std::cout << ret << std::endl;
    cout << INT_MIN << " " << INT_MAX << endl;  
    return 0;
}