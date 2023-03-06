
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define binary_to_gray(n) (n ^ n >> 1)
vector<int> grayCode(int n) {
    const size_t size = 1<<n;
    std::vector<int> ivec;
    for(size_t i = 0; i < size; ++i){
        ivec.push_back(binary_to_gray(i));
    }
    return ivec;

    /*
    std::vector<int> ivec;
    ivec.push_back(0);
    for(int i = 1; i <= n; ++i){
        const int high_bit = 1 << (i-1);
        for(int j = ivec.size()-1; j>=0; --j)
            ivec.push_back(ivec[j]|high_bit);
    }
    return ivec;
    */

}

int main (int argc, char* argv[])
{
    
    vector<int> ret = grayCode(2); 

    std::cout << "Print data: ";
    for(auto it = ret.cbegin(); it != ret.cend(); ++it){
        std::cout << *it << " ";
    }
    std::cout<< std::endl;

    int a = 13;
    cout<< a%7 << endl;

    return 0;

}