#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
/*
template <typename T>
void nextPermutation(T & nums) {
    if(nums.size() <= 1) return;
    auto it1 = nums.end() - 2, it3 = nums.end() - 1;
    while(it1 >= nums.begin() && *it1 >= *(it1+1)) --it1;
    if(it1>=nums.begin()) { //排除极端倒序情况
         while(it3 > nums.begin() && *it1 >= *it3) --it3;
        swap(*it1, *it3);
    }
    reverse(it1+1, nums.end());
}
*/


int factorial(int n)
{
    int result = 1;
    for(int i = n; i > 0; --i)
        result *= i;
    return result;
}

//Cantor decoding
template <typename T>
T kthPermutation(const T& seq, int k)
{   
    T result;
    --k;

    return result;
}

string getPermutation(int n, int k) {
    std::string str(n, '*');
    for(int i = 0; i<n; ++i)
        str[i] = i + 1 + '0';
    /*    
    for(int j = 1; j < k; ++j) //第一个序列是其本身
       nextPermutation(str);
    return str;
    */
   return kthPermutation(str, k);
}

int main (int argc, char* argv[])
{
    std::string str = getPermutation(4, 9);
    std::cout << str << std::endl;
    
    std::string s = "This Is An Example";//"123456";
    s.erase(s.begin());
    std::cout << s << std::endl;

   
    return 0;

}