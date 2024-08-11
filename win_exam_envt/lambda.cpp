#include <bits/stdc++.h>

int main(int argc, char* argv[]){
    //std::function<int(int, int)> sum = [&](int x, int y) -> int{
    //    return x+y;
    //};
    auto sum = [&](int x, int y) -> int{
        return x+y;
    };
    int a = sum(1, 3);
    std::cout << a << std::endl;
    return 0;
}