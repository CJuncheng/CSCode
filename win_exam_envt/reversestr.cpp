#include <iostream>
#include <vector>
using namespace std;

template <typename T>
inline void swap_(T &x, T &y)
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
