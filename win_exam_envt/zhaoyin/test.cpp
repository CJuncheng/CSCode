#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    static std::string solve(std::string s, std::string t) {
        // write code here
        if(s.size() < t.size())
        {
            std::string temp=s;
            s=t;
            t=temp;
        }
        int len1 = s.size();
        int len2 = t.size();
        int num1, num2, flag=0, sum;
        while(len1>0)
        {
    
            num1= s[len1-1] - '0';
            //cout << num1 << endl;

            if(len2>0) 
            {
                num2 = t[len2-1] - '0';
            } 
            else
            {
                num2 = 0;
            }
            sum = num1+num2+flag;
           
            s[len1-1] =  '0' + sum%10 ;
             //cout << s[len1-1] << endl;
            flag = sum / 10;
            len1--;
            len2--;
        }
        if(flag==1)
            s="1" + s;
        return s;
    }
};

int main() {
    std::string a = "33827272323232";
    std::string b = "45675234532466";
    std::string result = Solution::solve(a, b);
    std::cout << result << std::endl;
    return 0;
}