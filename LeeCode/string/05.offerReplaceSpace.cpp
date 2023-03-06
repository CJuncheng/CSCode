
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

string replaceSpace(string s) {
    /*
    // 方法1 开辟新的存储空间
    string str;
    for(size_t i = 0; i < s.size(); ++i){
            //cout << str1[i] << endl;
            if(s[i]== ' ')  str += "%20";
            else str+= s[i]; 
    }
    return str;
    */
    // 方法2 双指针
    const size_t oldLen = s.size();
    size_t count = 0;
    for(auto & c : s)
        if (c==' ') ++count;
    s.resize(oldLen+2*count);
    const size_t newLen = s.size();
    for(size_t i = oldLen-1, j = newLen-1; i < j; --i, --j){
        if(s[i]!= ' ') s[j] = s[i];
        else {
            s[j] = '0';
            s[j-1] = '2';
            s[j-2] = '%';
            j-=2;
        }
    }
    return s;


}

int main (int argc, char* argv[])
{
    string str = "We are happy.";
    string ret = replaceSpace(str);

    std::cout << ret << endl;
    //string ret = reverseStr(str, 2);
    //reverse(s.begin(), s.end());
    /*
    std::cout << "Print data: ";
    for(auto it = ret.cbegin(); it != ret.cend(); ++it){
        std::cout << *it << " ";
    }
    std::cout<< std::endl;
    */
    return 0;

}