#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

// auto &&, T&&为万能引用,在类型推导过程中，遇左则左边，遇右则右

template<typename T>
void bar(T && t, T v){
    cout <<  typeid(t).name() << endl;
    t = v;
}

int get_val(){
    return 5;
}

int main(int argc, char* argv[]){
    int i = 0;

    
    bar(get_val(), 1);
    auto && a = get_val();
    auto && b = i;
    cout <<  typeid(a).name() << endl;
    cout <<  typeid(b).name() << endl;
    return 0;
}

// 万能引用的应用是完美转发

