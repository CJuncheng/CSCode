
/* 实现 strStr() 函数。
 * https://leetcode.cn/problems/implement-strstr/
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
 * 示例 1: 输入: haystack = "hello", needle = "ll" 输出: 2
 * 示例 2: 输入: haystack = "aaaaa", needle = "bba" 输出: -1to use, copy, modify, distribute and sell this software
 * 说明: 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 对于本题而言，
 * 当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 */
#include <iostream>
#include <string>
using namespace std;

int strStr(const string& haystack, const string& needle) {
    if(needle.empty()) return 0;
    int n = haystack.size(), i = 0;
    int m = needle.size(), j =0;
    while(i<n&&j<m) {
        if(haystack[i]==needle[j]) {++i; ++j;}
        else {i+=1-j; j=0;}
    }
    return j==m ? i-j : -1; 
}



int main (int argc, char* argv[])
{

    const char * TStr = "hello";
    const char * PStr = "llu";

    int ret = strStr(TStr, PStr);
    std::cout << ret << std::endl;
    return 0;

}






