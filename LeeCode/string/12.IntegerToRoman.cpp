#include <iostream>
#include <vector>
#include <string>
using namespace std;

string intToRoman(int num) {
    const int intNum[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string romanNum[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string roman;
    for(size_t i = 0; num > 0; ++i){
        int count = num / intNum[i];
        for(; count >0; --count) roman += romanNum[i];
        num %= intNum[i];
    }
    return roman;
}

int main (int argc, char* argv[])
{
    const int ival = 3;
    string ret = intToRoman(ival);
    std::cout << ret << std::endl;
    return 0;
}