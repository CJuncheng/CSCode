#include <bits/stdc++.h>
// 定义行为像指针的类 --> 实现 shared_ptr 
template<typename T>
class SharedPtr{
public:
    // 默认构造函数
    SharedPtr(): ptr(nullptr), cnt(nullptr) {}
    // 直接构造函数 1 --> 从原生对象构造
    SharedPtr(const T& data) : ptr(new T(data)), cnt(new std::size_t(1)) {}
    // 直接构造函数 2 --> 从原生指针构造
    SharedPtr(T* ptr_) : ptr(ptr_), cnt(new std::size_t(1)) {}
    // 拷贝构造函数
    SharedPtr(const SharedPtr<T>& sh_ptr) : ptr(sh_ptr.ptr), cnt(sh_ptr.cnt) { ++*cnt; }
    // 拷贝赋值
    SharedPtr<T>& operator=(const SharedPtr<T>& rhs){
        if(this == &rhs) { // 解决自赋值问题
            return *this; 
        }
        ++*rhs.cnt; // 增加右侧运算对象的引用计数
        if(--*cnt==0) { //如果当前的shared_ptr已经有对象，则让其引用计数减少一，并判断引用是否为0，如果为0，则调用delete释放ptr
            delete ptr;
            delete cnt;
        }
        ptr = rhs.ptr;
        cnt = rhs.cnt;
        return *this;
    }

    ~SharedPtr() {
        if(--*cnt==0) { //如果当前的shared_ptr已经有对象，则让其引用计数减少一，并判断引用是否为0，如果为0，则调用delete释放ptr
            delete ptr;
            delete cnt;
        }
    }
    int getCnt(){ return *cnt; }
private:
    T *ptr; //一个指向对象的模板指针
    std::size_t *cnt;  //一个指向引用计数器的指针
};
int main(int argc, char* argv[]){
    SharedPtr<std::string> sh_ptr0("abc");
    std::cout << sh_ptr0.getCnt() << std::endl;

    SharedPtr<std::string> sh_ptr(new std::string("abc"));
    SharedPtr<std::string> sh_ptr2(sh_ptr);

    SharedPtr<std::string> sh_ptr3 = SharedPtr<std::string>(new std::string("abcd"));
    SharedPtr<std::string> sh_ptr4(sh_ptr3);
    sh_ptr2 = sh_ptr3;

    std::cout << sh_ptr2.getCnt() << std::endl;

    return 0;
}