#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int monotoneIncreasingDigits(int n) {
    string str = to_string(n);
    const int len = str.size();
    int flag = len;
    for(int i = len - 2; i >= 0; --i) {
        if(str[i] > str[i+1]){
            flag = i + 1;
            --str[i];
        }
    }
    for(int i = flag; i < len; ++i)
        str[i] = '9';
    return stoi(str);
}

int main (int argc, char* argv[])
{
    int ret = monotoneIncreasingDigits(332);
    cout << "Result: " << ret << endl;
    
    return 0;
}