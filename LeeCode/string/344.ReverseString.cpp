
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;


template <typename T>
void swap_(T &x, T &y)
{
    x = x^y;
    y = x^y;
    x = x^y;
}

void reverseString(vector<char>& s) {    
    const size_t len = s.size();
    for(size_t i = 0, j = len-1; i != len/2; ++i, --j) {
        cout << i << endl;
        swap_(s[i], s[j]);
    }
}


int main (int argc, char* argv[])
{
    vector<char> s = {'h','e','l','l','o'};
    reverseString(s);
    //reverse(s.begin(), s.end());
    std::cout << "Print data: ";
    for(auto it = s.cbegin(); it != s.cend(); ++it){
        std::cout << *it << " ";
    }
    std::cout<< std::endl;

    return 0;

}








