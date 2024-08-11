#include <iostream>
#include <string>

template<typename T>
void show_type(T t){
    std::cout << typeid(t).name() << std::endl;
}

template<typename T>
void normal_forwarding(T && t){ // 万能引用
    //show_type(static_cast<T &&> (t)); // 这里使用引用折叠实现，来实现完美引用
    show_type(std::forward<T> (t)); // 这里使用std::forward()，来实现完美引用

}

std::string get_string(){
    return "hi";
}

int main(int argc, char* argv[]){
    std::string s = "hello world";
   
    normal_forwarding(s);
    normal_forwarding(get_string());
    return 0;
}