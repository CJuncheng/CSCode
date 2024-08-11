#include <bits/stdc++.h>
#include <typeinfo>

template<typename T>
T retMax(T a, T b){
    std::cout << typeid(a).name() << std::endl;
    return a > b ? a : b;
}

int main(int argc, char* argv[]) {
    double a = 5, b = 9;
    std::cout << retMax(a, b) << std::endl;
    return 0;
}