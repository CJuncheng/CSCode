
/* 
 可以引入的库和版本相关请参考 “环境说明”
 Please refer to the "Environmental Notes" for the libraries and versions that can be introduced.
*/
#include <iostream>
#include <string>
using namespace std;

/* 
  以下为示例代码，仅供参考。请根据题目要求定义好方法及参数。
  The following is sample code for reference only. 
  Please define the methods and parameters according to the requirements of the question.
*/

string optstring(string s){
  /* 
    在这⾥写代码
    please write your code here
  */
  string res;
  const int n = s.size();
  for(int i = 0; i < n-1; ++i){
    int cnt = 1;
    while(i<n-1 && s[i]==s[i+1]) {
        ++i;
        ++cnt;
    }
    res += s[i] + to_string(cnt);
  }
  if(s[n-1] != s[n-2])
    res += s[n-1];
  return res.size() == s.size() ? s : res;
}

string solution(string s)
{
  return optstring(s);
}

int main(int argc, char *argv[])
{
    string s = "IIISSTTAAAD";
    cout << solution(s) << endl;

    return 0;
}