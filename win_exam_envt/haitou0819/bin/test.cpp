
#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;


int main() {
    int num = -1;
    int n = 4;
    if(n <= 2) num = 2;
    int pprev = 1, prev = 1;
    for(int i = 3; i <=n; ++i){
        num = pprev + prev;
        pprev = prev;
        prev = num;
    }
    cout << num << endl;

    
    return 0;
}