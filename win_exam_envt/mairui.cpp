/**
 * 
 * 题目：编写一个程序，把用户输入的二进制数（不考虑负数）转换为10进制数输出。例如程序运行结果：
请输入二进制数：01001
该二进制数的10进制为：9
请输入二进制数：1234
输入错误！
请输入二进制数：
考察点：C/C++语言编程基础，思考的全面性
 */
// 11111111111111111111111111111111
/** 
 * 1. 输入太长
 * 2. 输入
 */ 

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main(int argc, char* argv[]){
    string str; cin >> str;
    const int n = str.size();
    if(n > 32) {
        cout << "The input data is too long" << endl;
        return 0;
    }
    unsigned long res = 0;
    for(int i = n-1; i >= 0; --i){
        if(str[i] > '1' || str[i] < '0') {
            cout << "intput data error!" << endl;
            return 0;
        }
        if(str[i]-'0' >=0 && str[i]-'0' <=1){
            res += (str[i]-'0')* pow(2, n-1-i);
        }
        /*
        if(res > INT_MAX) {
            cout << "input data too " << endl;
            return 0;
        }
        */
    }
    cout << res << endl;
    return 0;
}

