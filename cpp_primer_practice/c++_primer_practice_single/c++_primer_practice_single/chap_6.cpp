#include <iostream>
#include <vector>
#include <string>
#include <cmath>

//practice_6_3 
int fact (int val)
{
    int ret = 1;
    while (val >= 1) {
        ret *= val--;
    }
    return ret;
}

int practice_6_4 (int val)
{
    if (val < 0)
        return -1;
    int ret = 1;
    while (val > 0)
        ret *= val--;
    return ret;
}

double practice_6_5 (double val)
{
    return abs(val);
}

//practice_6_6
size_t count_calls (void)
{
    static size_t crr = 0; // 函数调用结束后,这个局部变量仍然有效
    return ++ crr;
}

size_t practice_6_7(void)
{
    static size_t crr = 0;
    return crr++;
}

void practice_6_10 (int* p, int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

//practice_6_15
std::string::size_type fing_char (const std::string& s, char c, std::string::size_type& occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}

//practice_6_17
bool hasUpper (const std::string& s)
{
    for (auto c : s)
        if (isupper(c))
            return true;
    return false;
}

void changeToLower (std::string& s)
{
    for (auto& c : s)
        c = tolower (c);
}

void practice_6_18 (void)
{
    //bool compare (const matrix&, const matrix&);
    //std::vector<int>::iterator change_val (int&, std::vector<int>iterator);
}

//practice_6_21
int myCompare (const int& val, const int* p)
{
    return (val > *p) ? val : *p;
}

//practice_6_23
void print1 (const int* p)
{
    std::cout << *p << std::endl;
}

void print2 (const int* p, const int sz)
{
    int i = 0;
    for (int i = 0; i != sz; ++i)
        std::cout << p[i] << std::endl;
}

void print3 (const int *b, const int *e)
{
    for (auto p = b; p != e; ++p)
        std::cout << *p << std::endl;        
}

//practice_6_27 
int iCount (std::initializer_list <int> ilist)
{
    int count = 0;
    for (auto val : ilist)
        count += val;
    return count;
}

//practice_6_33
void print_vec (const std::vector<int> iVec,const size_t index)
{
    size_t sz = iVec.size();
    if (!iVec.empty() && index < sz) {
        std::cout << iVec[index] << std::endl;
        print_vec (iVec, index+1);
    }
}

/*
//practice_6_36
//string (&fun(void)) [10];
typedef std::string arrT [10];
arrT& fun (void);

auto fun (void) -> std::string (&) [10];

std::string arrT [10];
decltype (arrT) & fun (void);
*/

//practice_6_42
std::string make_plural (size_t crr, const std::string& word, const std::string& ending = "s")
{
    return  (crr > 0) ? word + ending : word;
}

void debugFun (void)
{
    std::cerr << "Error: " << __FILE__ 
              << " : in function " << __func__
              << " at line " << __LINE__ << std::endl
              << "      Compiled on " << __DATE__ 
              << " at " << __TIME__ << std::endl;
}

//practice_6_47 递归算法
void print_vec_6_47 (const std::vector<int> iVec,const size_t index)
{
    size_t sz = iVec.size();
    #ifndef NDEBUG
        std::cout << "Vector对象的大小是：" << sz << std::endl;
    #endif
    if (!iVec.empty() && index < sz) {
        std::cout << iVec[index] << std::endl;
        print_vec (iVec, index+1);
    }
}


void fun (void);
void fun (int);
void fun (int, int);
//practice_6_51
void fun (void)
{
    std::cout << "该函数无需参数" << std::endl;
}

void fun (int)
{
    std::cout << "该函数有一个整型参数" << std::endl;
}

void fun (int a, int b)
{
    std::cout << "该函数有两个整型参数" << std::endl;
}


void fun (double a, double b = 3.14)
{
    std::cout << "该函数有两个双精度浮点型参数" << std::endl;
}

//practice_6_54
int func (int, int);

int fun1 (int a, int b)
{
    return a + b;
}

int fun2 (int a, int b)
{
    return a - b;
}

int fun3 (int a, int b)
{
    return a * b;
}

int fun4 (int a, int b)
{
    return a / b;
}

void computer (int a, int b, int (*p)(int, int))
{
    std::cout << p (a,b) << std::endl;
}
int main (int argc, char* argv[])
{
    //std::cout << fact(5) << std::endl;
    //debugFun ();
    
    /*
    //practice_6_4
    int num = 0;
    std::cout << "Enter a num:" << std::endl;
    std::cin >> num;
    std::cout << practice_6_4 (num) << std::endl;
    */

    //std::cout << practice_6_5 (-7) << std::endl;
    
    /*
    //practice_6_6
    for (int i = 0; i != 10; ++i)
        std::cout << count_calls() << std::endl;
    */
    
    /*
    for (int i = 0; i != 5; ++i)
        std::cout << practice_6_7 () << std::endl;
    */
    
    /*   
    int a = 5, b = 10;
    std::cout << a << ' ' << b << std::endl;
    practice_6_10  (&a,&b);
    std::cout << a << ' ' << b << std::endl;    
    */
    
    /*    
    //practice_6_15
    std::string s = "rtyuiopyubbbo";
    std::string::size_type occurs = 0;
    auto index = fing_char (s,'o',occurs);
    std::cout << index << ' ' << occurs << std::endl;
    */
    
    /*
    //practice_6_17    
    std::string s("ghhhyHHh");
    std::cout << hasUpper(s) << std::endl;
    changeToLower (s);
    std::cout << s << std::endl;
    */
    
    //int a = 5, b = 6;
    //std::cout << myCompare (a,&b) << std::endl;
    
    /*
    //practice_6_24
    int i = 0, j[2] = {0, 1};
    print1 (&i);
    print1 (j);

    print2 (&i, 1);
    print2 (j, 2);
    
    print3 (std::begin (j), std::end (j));
    */

    /*
    //practice_6_25
    std::string str;
    for (int i = 0; i != argc; ++i)
        //str += argv[i];
    std::cout << argv[i] << std::endl;
    */

    /*
    std::initializer_list <int> il{1,2,4};
    std::cout << iCount ({1,2,4,5}) << std::endl;
    std::cout << iCount (il) << std::endl;
    */

    //std::vector <int> iVec = {1,3,5,7,9,11,13,15};
    //print_vec(iVec, 0);

    //practice_6_47
    //std::vector<int> iVec = {1,3,5,7,9,11,13};
    //print_vec_6_47(iVec,0);

    //practice_6_51
    //fun (2.56, 42);
    //fun (42);
    //fun (42,0);
    //fun (2.56, 3.14);

    //practice_6_54 要求理解函数指针，函数指针作为变量使用
    //decltype(func) *p1 = fun1, *p2 = fun2, *p3 = fun3, *p4 = fun4;
    constexpr int a = 5, b = 10;
    std::vector <decltype(func)*> vF = {fun1,fun2,fun3,fun4};
    for (auto funp : vF)
        computer (a, b, funp);
    return 0;
}


