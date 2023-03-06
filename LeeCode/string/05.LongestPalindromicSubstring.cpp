#include <iostream>
#include <string>
using namespace std;

// 双指针法 O(n^2)
int left_ = 0, right_ = 0, maxLen_ = 0;
inline
void extend(const string& s, int i, int j, int len)
{
    while(i>=0&&j<len&&s[i]==s[j]){
        if(j-i+1>maxLen_){
            left_ = i;
            right_ = j;
            maxLen_ = j-i+1;
        }
        --i;
        ++j;
    }
}
string longestPalindrome(string s) {
    
    const int len = s.size();
    for(int i=0; i < len; ++i){
        extend(s, i, i, len);
        extend(s, i, i+1, len);
    }
    return s.substr(left_, right_-left_+1);
}


// 马拉车算法（Manacher Algorithm） O(n)
// https://www.zhihu.com/question/37289584#:~:text=%E9%A9%AC%E6%8B%89%E8%BD%A6%E7%AE%97%E6%B3%95%20Manacher%E2%80%98s,Algorithm
string preProcess(const string& s) 
{
    int len = s.size();
    if(len == 0) return "^$";
    string ret = "^";
    for(int i = 0; i < len; ++i) ret += "#" + s.substr(i, 1); 
    ret += "#$";

    return ret;
}

string manacherAlgorithm(string s) 
{
    /*
    string T = proProcess(s);
    int len = s.size();
    int P[len];
    int C = 0, R = 0;
    for(int i = 1; i < len-1; ++i) {
        int i_mirror = 2 * C - i; // equals to i' = C - (i-C)
        P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
        // 碰到之前讲的三种情况时候，需要利用中心扩展法
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) P[i]++;
         // 判断是否需要更新 R
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    // 找出 P 的最大值
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < len - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    int start = (centerIndex - maxLen- 1) / 2; //求原字符串下标起点
    return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
    */
   string T = preProcess(s);
    const int n = T.length();
   
    int P[n];
    int C = 0, R = 0;
    for (int i = 1; i < n - 1; i++) {
        int i_mirror = 2 * C - i; // equals to i' = C - (i-C)
        P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
        // Attempt to expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
        P[i]++;
        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    // Find the maximum element in P.
    int max_len = 0;
    int center_index = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > max_len) {
            max_len = P[i];
            center_index = i;
        }
    }
    return s.substr((center_index - 1 - max_len) / 2, max_len);
}


int main (int argc, char* argv[])
{
    
    string str = "babad";
    string ret = manacherAlgorithm(str);
    std::cout << ret << std::endl;
    return 0;
}