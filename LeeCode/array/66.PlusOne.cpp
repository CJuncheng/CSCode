#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> plusOne(vector<int>& digits) {
    /*
    const size_t n = digits.size();

    size_t flag=0;                          
    for(size_t i=0; i < n; ++i) {
        if(digits[i] == 9) ++flag;
    }
    if(flag==n){
        digits.assign(n, 0);
        digits.insert(digits.begin(), 1);
        return digits;
    }

    ++digits[n-1];
    for (size_t i = 0; i < n; ++i)
        if(digits[n-1-i]>9) {
            //if(n-1-i==0) return {0};
            ++digits[n-i-2]; digits[n-1-i] -=10; 
        }
    return digits;
    */
   /*
    const size_t n = digits.size();
    for (size_t i = 0; i < n; ++i){
        ++digits[n-1-i];
        digits[n-1-i] %= 10;
        if(digits[n-1-i] != 0) return digits;
    }
    digits.assign(n, 0);
    digits.insert(digits.begin(), 1);
    return digits
    */
   /*
    const size_t n = digits.size();
    int c = 1; //进位
    for_each(digits.rbegin(), digits.rend(), [&c](int &d){
        d += c;
        c = d /10;
        d %= 10;
    } );
    if ( c>0) {
        digits.assign(n, 0);
        digits.insert(digits.begin(), 1);
    }
    return digits;
    */

    const size_t n = digits.size();
    for(auto it = digits.rbegin(); it != digits.rend(); ++it) {
        ++*it;
        *it %= 10;
        if (*it !=0) return digits;
    }
    digits.assign(n, 0);
    digits.insert(digits.begin(), 1);
    return digits;

}

int main (int argc, char* argv[])
{
    vector<int> digits = {9,9,9};
    vector<int> ret = plusOne(digits);

    std::cout << "Print data: ";
    for(auto it = ret.cbegin(); it != ret.cend(); ++it){
        std::cout << *it << " ";
    }
    std::cout<< std::endl;

    return 0;

}