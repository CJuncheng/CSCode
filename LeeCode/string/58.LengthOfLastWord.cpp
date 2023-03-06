#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lengthOfLastWord(string s) {
    int last = s.size()-1;
    while(last>=0&&s[last] == ' ')  --last;
    int count = 0;
    while(last>=0&&s[last] !=' '){
        --last;
        ++count;
    }
    return count;
}

int main (int argc, char* argv[])
{
    const string str = "   fly me   to   the moon  ";
    int ret = lengthOfLastWord(str);
    std::cout << ret << std::endl;
    return 0;

}