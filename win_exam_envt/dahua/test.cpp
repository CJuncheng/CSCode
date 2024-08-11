#include<iostream>
using namespace std;

static int func(char j) {
    static char i = j;
    return ++i;
}

int main(int argc,const char argv){
    int i = 0;
    int j = 128;
    for(; j!=0; --j){
        i =func(j);
    }
    std::cout <<i<<std::endl;
    return 0;
}
