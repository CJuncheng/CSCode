
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    const int len = s.size();
    int slow = 0;
    for(int fast = 0; fast < len; ++fast) {
        if((s[fast]>='A'&& s[fast]<='Z')||(s[fast]>='a' && s[fast]<='z')||(s[fast]>='0' && s[fast]<='9')){
            if(s[fast]>='A'&& s[fast]<='Z') s[fast] += 'a'-'A';
            s[slow++] = s[fast];
        }
    }
    for(int i = 0, j = slow-1; i < j; ++i, --j)
        if(s[i]!=s[j]) return false;
    return true;

}

int main (int argc, char* argv[])
{
    string str = "0P";
    bool ret = isPalindrome(str);
    std::cout << ret << endl;

    return 0;

}