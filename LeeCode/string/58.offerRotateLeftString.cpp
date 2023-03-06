
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

string reverseLeftWords(string s, int n) {
    /*
    //方法1 开辟新的内存空间
    string newStr;
    const int len = s.size();
    for(int i = n; i < len; ++i) newStr += s[i];
    for(int i = 0; i < n; ++i) newStr += s[i];
    return newStr;
    */

    //方法2 不开辟多余存储空间
    reverse(s.begin(),s.begin()+n);
    reverse(s.begin()+n, s.end());
    reverse(s.begin(), s.end());

}

int main (int argc, char* argv[])
{
    string str = "lrloseumgh";
    const int k = 6;
    string ret = reverseLeftWords(str, k);

    std::cout << ret << endl;
   
    return 0;

}