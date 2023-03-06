#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void swap_(T &x, T &y)
{
    x = x^y;
    y = x^y;
    x = x^y;
}

template <typename Iter>
inline void reverseK(Iter first, Iter last) {
    for(--last; first < last; ++first, --last) {
        //cout << i << endl;
        swap_(*first, *last);
    }
}

//每隔k个反转k个，末尾不够k个时全部反转；
string reverseStr(string s, int k) {
    int len = s.size();
    int index = 0;
    for(int i = 0; i < len; i+=2*k) {
        if(i+k <= len) {
            reverseK(s.begin()+i, s.begin()+i+k);
        } else {
            reverseK(s.begin()+i, s.end());
        }     
    } 
    cout << index << endl;
    return s;
}



int main (int argc, char* argv[])
{
    string str = "abcd";
    //cout << str[0] << endl;
    
    string ret = reverseStr(str, 2);
    //reverse(s.begin(), s.end());
    std::cout << "Print data: ";
    for(auto it = ret.cbegin(); it != ret.cend(); ++it){
        std::cout << *it << " ";
    }
    std::cout<< std::endl;
    
    return 0;

}