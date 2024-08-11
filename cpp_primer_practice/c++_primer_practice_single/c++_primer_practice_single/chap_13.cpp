#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

// practice_13_1
/**
 * 如果构造函数的第一个参数是自身类类型的引用，且所有其他参数(如果有的话)都有默认值，则此构造函数时就是拷贝构造函数。拷贝构造函数在以下几种情况下会被使用：
 *   拷贝初始化(用 = 定义变量)
 *   将一个对象作为实参传递给非引用类型的形参
 *   一个返回类型为非引用类型的函数返回一个对象
 *   用花括号列表初始化一个数组中的元素或一个聚合类中的成员
 *   初始化标准容器或调用其 insert/push 操作时，容器会对其元素进行拷贝初始化
 */ 

//practice_13_5
void practice_13_5(void) 
{
    /**
     * HasPtr(const string& hp){
     *      ps = new string(*hp.ps)
     *      i = hp.i;
     * }
     * 
     */
}

void practice_13_8(void) 
{
    /*
    HasPtr&
    HasPtr::operator=(const HasPtr &rhs){
        auto newps = new string(*rhs.ps);
        delete ps;
        ps = newps;
        i = rhs.i;
        return *this;
    }
    */
}

class HasPtr{
public:
    friend void swap(HasPtr& lhs, HasPtr& rhs);
    HasPtr(const string &s = string()): ps(new string(s)), i(0) {} 
    HasPtr(const HasPtr& p): ps(new string(*p.ps)), i(p.i){} // 拷贝构造函数
    HasPtr& operator=(const HasPtr&); // 拷贝赋值运算符
    HasPtr& operator=(const string&); // 赋予新的string
    string& operator*();              // 解引用
    bool operator<(const HasPtr&) const; //比较运算
    ~HasPtr(){ delete ps; }
private:
    string* ps;
    int i ;
};

inline
HasPtr& HasPtr::operator=(const HasPtr& rhs) // 拷贝赋值运算符
{
    auto newps = new string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;
    return *this;
}

inline
HasPtr& HasPtr::operator=(const string& rhs) // 拷贝赋值运算符
{
    *ps = rhs;
    return *this;
}

string& HasPtr::operator*() 
{
    return *ps;
}

bool HasPtr::operator<(const HasPtr& rhs) const
{
    return *ps < *rhs.ps;

}

void practice_13_22(void) 
{
    HasPtr h("hi mom!");
    HasPtr h2(h);
    HasPtr h3 = h;
    h2 = "hi dad!";
    h3 = "hi son!";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
}


class HasPtr1{
public:
    
    HasPtr1(const string &s = string()): ps(new string(s)), i(0), use(new size_t(1)){} 
    HasPtr1(const HasPtr1& p): ps(p.ps), i(p.i), use(p.use){
        ++*use;
    } // 拷贝构造函数
    HasPtr1& operator=(const HasPtr1&); // 拷贝赋值运算符
    HasPtr1& operator=(const string&); // 赋予新的string
    string& operator*();              // 解引用
    ~HasPtr1(); 
private:
    string* ps;
    int i ;
    size_t *use;
};

inline
HasPtr1& HasPtr1::operator=(const HasPtr1& rhs) // 拷贝赋值运算符
{
    ++*rhs.use;
    if(--*use==0){
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

inline
HasPtr1& HasPtr1::operator=(const string& rhs) // 拷贝赋值运算符
{
    *ps = rhs;
    return *this;
}

string& HasPtr1::operator*() 
{
    return *ps;
}

HasPtr1::~HasPtr1()
{
    if(--*use == 0){
        delete ps;
        delete use;
    }
}

// practice_13_27

void practice_13_27(void)
{
    HasPtr1 h("hi mom!");
    HasPtr1 h2 = h;
    h = "hi dadi!";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl; 
}

void swap(HasPtr& lhs, HasPtr& rhs)
{
    std::swap(lhs.ps, rhs.ps);
    std::swap(lhs.i, rhs.i);
}
void practice_13_30(void)
{
    HasPtr h("hi mom!");
    HasPtr h2(h);
    HasPtr h3 = h;
    h2 = "hi dad!";
    h3 = "hi son!";
    swap(h2, h3);
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
} 

void practice_13_31(void)
{
    vector<HasPtr> vecH;
    const int n = 10;
    for(int i = 0; i < 10; ++i)
        vecH.push_back(to_string(n-i));
    for(auto p : vecH)
        cout << *p << " ";
    cout << endl;
    sort(vecH.begin(), vecH.end());

    for(auto p : vecH)
        cout << *p << " ";
    cout << endl;
}

int main(int argc, char **argv)
{
    //practice_13_22();
    //practice_13_27();
    //practice_13_30();
    practice_13_31();
    return 0;
}
