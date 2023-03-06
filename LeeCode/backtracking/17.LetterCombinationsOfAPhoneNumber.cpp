#include <iostream>
#include <vector>

using namespace std;
const string letterMap[10] = {
    " ",
    " ",
    "abc",
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
};
vector<string> res;
string str;
void backTracking(const string& digits, int index){
    if(index == (int)digits.size()) {
        res.push_back(str);
        return;
    }
    int digit = digits[index] - '0';
    string letter = letterMap[digit];
    for(int i = 0; i < (int)letter.size(); ++i){
        str.push_back(letter[i]);
        backTracking(digits, index+1);
        str.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if(digits.size() == 0) return res;
    backTracking(digits, 0);
    return res;

}

int main (int argc, char* argv[])
{
    string s = "23";
    vector<string> ret = letterCombinations(s);
    for (auto it = ret.begin(); it != ret.end(); ++it)
           std::cout << *it << std::endl;
    return 0;
}