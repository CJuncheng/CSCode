#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int climbStairs(int n) { 
    /*
    //递归
    if(n == 1) return 1;
    if(n == 2) return 2;
    return climbStairs(n-1) + climbStairs(n-2);
    */
    //迭代
    /*
    if(n == 1) return 1;
    if(n == 2) return 2;
        
    int* d =new int[n]();
    d[0] = 1;
    d[1] = 2;

    for(int i = 2; i < n; ++i ){
        d[i] = d[i-1] + d[i-2];
    }
    return d[n-1];
    */
   int prev = 0, cur = 1;
   for(int i =1 ; i <= n; ++i)
   {
        int tmp = cur;
        cur += prev;
        prev = tmp;
   }
   return cur;
}

int main (int argc, char* argv[])
{
    std::cout<< climbStairs(5) << std::endl;
    
   
    return 0;

}