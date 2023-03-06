#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    a.size() > b.size() ? b.resize(a.size(), '0') : a.resize(b.size(),'0');
    string c;
    int carry = 0;
    for(size_t i = 0; i < a.size(); ++i) {
        int tmp = (a[i]-'0') + (b[i]-'0')+carry;
        c += tmp%2+'0';
        carry = tmp/2;
    }
    if(carry == 1) c += '1';
    reverse(c.begin(), c.end());
    return c;
}

int main (int argc, char* argv[])
{
    string str1 = "11";
    string str2 = "1";
    string ret = addBinary(str1, str2);
    std::cout << ret << std::endl;
    return 0;
}