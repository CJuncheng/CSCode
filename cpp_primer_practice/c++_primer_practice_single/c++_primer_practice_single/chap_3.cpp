#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <iterator>
#include <bitset>
#include <cstring>
#include <sys/time.h>

void practice_3_2 (void)
{
/*    std::string line;
    std::cout << "Please input a line:";
    while (getline(std::cin, line))
        std::cout << line << std::endl;
    std::cout << std::endl;
*/    std::string word;
    std::cout << "Please input a word:";
    while (std::cin >> word)
        std::cout << word << " ";
    std::cout << std::endl;
}

void practice_3_4 (void)
{
    std::string string1, string2;
    std::cout << "please input two strings:" << std::endl;
    std::cin >> string1 >> string2;
    if (string1 < string2)
        string1 = string2;
    std::cout << string1 <<std::endl;
    auto string_length = string1.size();
    if (string1.size() < string2.size()) 
        string_length = string2.size();
    std::cout << string_length << std::endl;  
}

void practice_3_5 (void)
{
    std::string string1, string2,string3;
    std::cout << "please input 3 strings:";
    std::cin >> string1 >> string2 >> string3;
    std::string string_fusion = string1 + string2 + string3;
    std::cout << string_fusion << std::endl;
    std::string string_fusion_tab = string1 + " " + string2 + " " +string3;
    std::cout << string_fusion_tab << std::endl;
}

void practice_string (void)
{
    /*
    std::string s("Hello World!!!");
    decltype(s.size()) punct_count = 0;
    for (auto c : s)
        if (ispunct(c))
            ++punct_count;
    std::cout << punct_count << " punctuation characters in " << s << std::endl;

    for (auto &c : s)
        c = toupper (c);
    std::cout << s << std::endl;
    */
    /*
    std::string s("some string");
    if (!s.empty())
        s[0] = toupper(s[0]);
    std::cout << s << std::endl;
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
        s[index] = toupper(s[index]);
    std::cout << s << std::endl;
    */
    const std::string hex_digits = "0123456789ABCDEF";
    std::string::size_type n;
    char result;
    std::cout << "Enter a series of numbers between 0 and 15: " << std::endl; 
    while (std::cin >> n) 
        if (n < hex_digits.size())
            std::cout << hex_digits[n] << ' ';
    std::cout << std::endl;     
}

void practice_3_6 (void)
{
    std::string s("some string");
    for (auto &c : s)
        c = 'X';
    std::cout << s << std::endl;
}

void practice_3_8 (void)
{
    std::string s("some string");
    /*
    //while loop
    int i = 0;
    while (s[0] != '\0')
    { 
       s[i] = 'X';
       ++i;
    }
    std::cout << s << std::endl;
    */
    // for loop
    for(int i = 0; i != s.size(); ++i)
        s[i] = 'X';
    std::cout << s << std::endl;
}

void practice_3_10 (void)
{
    std::string s("some???string!!!");
    //method1
    for(auto c : s)
        if (!ispunct(c))
            std::cout << c;
    std::cout << std::endl;
    //method2 is better
    std::string result;
    for (decltype(s.size()) index = 0; index != s.size(); ++index)
        if (!ispunct(s[index]))
            result += s[index];
    std::cout << result << std::endl;
}

void practice_3_14 (void)
{
/*    std::vector<int> ivec;
    std::cout << "Enter a series of int number:" << std::endl;
    int n = 0;
    char cont = 'y';
    while (std::cin >> n)
    {
        ivec.push_back (n);
        std::cout << "您想要继续吗(y or n)?" << std::endl;
        std::cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }*/
//    for(auto mem : ivec)
  //      std::cout << mem <<' ';
   // std::cout << std::endl;
    
    std::cout << "Enter a series of int numbers:";
    int i = 0, count = 0;
    while (std::cin >> i)
    {
        std::cout << "The " << ++count << "th is " << i <<std::endl;    
        if (i == '\n') 
            break;
    }
}

void practice_3_16 (void)
{
    std::vector <int> v1;
    std::vector <int> v2(10);
    std::vector <int> v3(10,42);
    std::vector <int> v4{10};
    std::vector <int> v5{10,42};
    std::vector <std::string> v6{10};
    std::vector <std::string> v7{10,"hi"};

    std::cout << "The numbers of V1 is:" << v1.size() << std::endl;
    if (v1.size() > 0)
    {
        std::cout << "The elements of V1 is:";
        for (auto c : v1)
        std::cout << c << ' ';
        std::cout << std::endl;
    }


    std::cout << "The numbers of V2 is:" << v2.size() << std::endl;
    if (v2.size() > 0)
    {
        std::cout << "The elements of V2 is:";
        for (auto c : v2)
        std::cout << c << ' ';
        std::cout << std::endl;
    }

    std::cout << "The numbers of V3 is:" << v3.size() << std::endl;
    if (v3.size() > 0)
    {
        std::cout << "The elements of V3 is:";
        for (auto c : v3)
        std::cout << c << ' ';
        std::cout << std::endl;
    }

    std::cout << "The numbers of V4 is:" << v4.size() << std::endl;
    if (v4.size() > 0)
    {
        std::cout << "The elements of V4 is:";
        for (auto c : v4)
        std::cout << c << ' ';
        std::cout << std::endl;
    }

    std::cout << "The numbers of V5 is:" << v5.size() << std::endl;
    if (v5.size() > 0)
    {
        std::cout << "The elements of V5 is:";
        for (auto c : v5)
        std::cout << c << ' ';
        std::cout << std::endl;
    }

    std::cout << "The numbers of V6 is:" << v6.size() << std::endl;
    if (v6.size() > 0)
    {
        std::cout << "The elements of V6 is:";
        for (auto c : v6)
        std::cout << c << ' ';
        std::cout << std::endl;
    }

    std::cout << "The numbers of V7 is:" << v7.size() << std::endl;
    if (v7.size() > 0)
    {
        std::cout << "The elements of V7 is:";
        for (auto c : v7)
        std::cout << c << ' ';
        std::cout << std::endl;
    }   
}

void practice_3_17 (void)
{
    std::string s;
    std::vector <std::string> svec;
    std::cout << "Enter a series of strings:" << std::endl;
    char cont = 0;
    while (std::cin >> s)
    {
       svec.push_back(s);
        std::cout << "你想要继续输入吗(y or n):" << std::endl;
        std::cin >> cont;
        if (cont != 'y' && cont !='Y')
            break;
        std::cout << "请输入下一个词:" << std::endl;
    }
    std::cout << "转换后的结果是:" << std::endl;    
    for (std::string &s_temp : svec )
    {
        for (char &c : s_temp)
            c = toupper (c);
        std::cout << s_temp << std::endl;
    }
}

void practice_3_19 (void)
{
    //method1
    std::vector <int> ivec1(10,42);
    //method2
    std::vector <int> ivec2;
    for (decltype(ivec2.size()) index = 0; index != 10; ++index)
        ivec2.push_back(42);
    //method3
    std::vector <int> ivec3(10);
    for (auto &mem : ivec3)
        mem = 42;
}

void practice_3_20 (void)
{   
    std::vector <int> ivec;
    std::vector<int>::size_type cont = 18;
    for (decltype(ivec.size()) index = 0; index != cont; ++index)
        ivec.push_back(index);
  
    if (ivec.size() == 0)
        std::cout << "ivec没有数据" << std::endl;
    for (decltype(ivec.size()) i = 0; i < ivec.size() - 1; i+=2)
        std::cout << ivec[i]+ivec[i+1] << std::endl;
    if(ivec.size() %2 != 0)
        std::cout << ivec[ivec.size()-1] << std::endl;

    std::cout << "首尾和" << std::endl;
    for (decltype(ivec.size()) i = 0; i < ivec.size() / 2; ++i)
        std::cout << ivec[i]+ivec[ivec.size()-1-i] << std::endl;
    if (ivec.size()%2 != 0)
        std::cout << ivec.size() / 2 << std::endl; 
}

void practice_3_21 (void)
{
    std::vector <int> v1;
    std::vector <int> v2(10);
    std::vector <int> v3(10,42);
    std::vector <int> v4{10};
    std::vector <int> v5{10,42};
    std::vector <std::string> v6{10};
    std::vector <std::string> v7{10,"hi"};

    std::cout << "The numbers of V1 is:" << v1.size() << std::endl;
    if (v1.cbegin() != v1.cend())
    {
        std::cout << "The elements of V1 is:";
        for (auto it = v1.cbegin(); it != v1.cend(); ++it)
            std::cout << *it;
        std::cout << std::endl;
    }

    std::cout << "The numbers of V2 is:" << v2.size() << std::endl;
    if (v2.cbegin() != v2.cend())
    {
        std::cout << "The elements of V2 is:";
        for (auto it = v2.cbegin(); it != v2.cend(); ++it)
            std::cout << *it << ' ';
        std::cout << std::endl;
    }

    std::cout << "The numbers of V3 is:" << v3.size() << std::endl;
    if (v3.cbegin() != v3.cend())
    {
        std::cout << "The elements of V3 is:";
        for (auto it = v3.cbegin(); it != v3.cend(); ++it)
            std::cout << *it << ' ';
        std::cout << std::endl;
    }

    std::cout << "The numbers of V4 is:" << v4.size() << std::endl;
    if (v4.cbegin() != v4.cend())
    {
        std::cout << "The elements of V4 is:";
        for (auto it = v4.cbegin(); it != v4.cend(); ++it)
            std::cout << *it << ' ';
        std::cout << std::endl;
    }

    std::cout << "The numbers of V5 is:" << v5.size() << std::endl;
    if (v5.cbegin() != v5.cend())
    {
        std::cout << "The elements of V5 is:";
        for (auto it = v5.cbegin(); it != v5.cend(); ++it)
            std::cout << *it << ' ';
        std::cout << std::endl;
    }

    std::cout << "The numbers of V6 is:" << v6.size() << std::endl;
    if (v6.cbegin() != v6.cend())
    {
        std::cout << "The elements of V6 is:";
        for (auto it = v6.cbegin(); it != v6.cend(); ++it)
            std::cout << *it << ' ' ;
        std::cout << std::endl;
    }

    std::cout << "The numbers of V7 is:" << v7.size() << std::endl;
    if (v7.cbegin() != v7.cend())
    {
        std::cout << "The elements of V7 is:";
        for (auto it = v7.cbegin(); it != v7.cend(); ++it)
            std::cout << *it << ' ';
        std::cout << std::endl;
    }  
}

void practice_3_22 (void)
{
    std::string s;
    std::vector <std::string> svec{"www","er","", "gf"};
   /* std::cout << "Enter a series of strings:" << std::endl;
    while (std::cin >> s)
    {
        svec.push_back(s);
        if (s == "end")
            break;    
    }
    */
    for (auto it = svec.begin(); it != svec.end() && !it->empty(); ++it)
    {    
        for (auto it2 = it->begin(); it2 != it->end(); it2++)
            (*it2) = toupper (*it2);
        std::cout << *it << std::endl;
    }

}

void practice_3_23 (void)
{
    const std::vector<int>::size_type cont =10;
   //  const decltype(ivec.size()) cont =10;
    std::vector <int> ivec;
    for (decltype(ivec.size()) index = 0; index != cont; ++index)
        ivec.push_back(index);
    for (auto it = ivec.begin(); it != ivec.end(); ++it)
    {
        *it = 2*(*it);
        std::cout << *it << std::endl;
    }
}

void practice_3_24 (void)
{
    std::vector <int> ivec;
    std::vector<int>::size_type cont = 11;
    for (decltype(ivec.size()) index = 0; index != cont; ++index)
        ivec.push_back(index);
    
    if (ivec.size() == 0)
        std::cout << "ivec没有数据" << std::endl;
    for (auto it = ivec.cbegin(); it < ivec.cend()-1 ; ++it)
        std::cout << (*it + *(++it)) << ' ';       
    if(ivec.size() %2 != 0)
        std::cout << *(ivec.end() - 1) << std::endl;
    std::cout << std::endl;

    std::cout << "首尾和" << std::endl;
    auto mid = ivec.begin() + (ivec.end() - ivec.begin())/2;
    for (auto it = ivec.begin(); it < mid ; ++it)
        std::cout << ((*it) + *(ivec.begin()+(ivec.end()-it)-1)) << ' ';
    if (ivec.size()%2 != 0)
        std::cout << *(mid)  << std::endl; 
    std::cout << std::endl;  
}

void practice_3_25 (void)
{

}

void practice_3_26 (void)
{
    //迭代器的加法不合法
}

void practice_3_28 (void)
{
    //The disadvantages of arrays relative to vectors
    //灵活度:向量可以自由添加对象变量, 数组是固定的
    //获取数组长度的方式:向量使用size(), 数组使用sizeof();
}

void practice_3_31 (void)
{
    constexpr size_t cont = 10;
    int a[cont];
    for (size_t i = 0; i < cont; ++i)
        a[i] = i;
    for (auto c : a)
        std::cout << c << " ";
    std::cout << std::endl;
}

void practice_3_32 (void)
{
    constexpr size_t cont = 10;
    int a[cont];
    for (size_t i = 0; i < cont; ++i)
        a[i] = i;
    for (auto c : a)
        std::cout << c << " ";
    std::cout << std::endl;
    
    std::vector<int> ivec;
    for (size_t i = 0; i < cont; ++i)
        ivec.push_back (a[i]);
    for (auto c : ivec)
        std::cout << c << " ";
    std::cout << std::endl;
}

void practice_3_35 (void)
{
    int ia[10] = {};
    for (int i = 0; i < 10; ++i)
        ia[i] = i;
    int *beg = std::begin(ia);
    int *last = std::end(ia);
    for (auto p = beg; p != last; p++)
    {
        (*p) = 0;
    }
    for (auto c : ia)
        std::cout << c << std::endl;
}

void practice_3_36 (void)
{
}

void practice_3_37 (void)
{
    const char ca [] = {'h', 'e', 'l', 'l', 'o', '\0'};
    const char *cp = ca;
    while (*cp) {
        std::cout << *cp ;
        ++cp;
    }
    std::cout << std::endl;
}
/*
void print ()
{

}

template <typename T, typename... Types>
void print (const T& firstArg, const Types&... args)
{
    std::cout << firstArg << std::endl;
    print (args...);
}

*/

void practice_3_39 (void)
{
    /**
    //c++风格字符串
    std::string str1, str2;
    std::cout << "Enter two strings" << std::endl;
    std::cin >> str1 >> str2;
    if (str1 > str2)
        std::cout << "第一个字符串大于第二个字符串" << std::endl;
    if (str1 < str2)
        std::cout << "第一个字符串小于第二个字符串" << std::endl;
    else 
        std::cout << "两个字符串相等" << std::endl;
    */
    //c风格字符串
    char str1[80], str2[80];
    std::cout << "请输入两个字符串:" << std::endl;
    std::cin >> str1 >> str2 ;
    auto result = strcmp (str1, str2);
    switch (result)
    {
        case 1:
            std::cout << "第一个字符串大于第二个字符串" << std::endl;
            break;
        case -1:
            std::cout << "第一个字符串小于第二个字符串" << std::endl;
            break;
        case 0:
            std::cout << "两个数相等" << std::endl;
            break;
        default:
            std::cout << "未定义的结果" << std::endl;
            break;
    }

}

void practice_3_40 (void)
{
    char str1 [] = "Welcome to ";
    char str2 [] = "C++ family!";
    char result [80];
    //char result [strlen(str1)+strlen(str2)-1];
    //strcat (str1, str2);
    //std::cout << str1 << std::endl;   
    //strcpy (result, str1);
   // strcat (result, str2);
   // std::cout << result << std::endl;

}

void practice_3_41 (void)
{
//    int int_arr [] = {0, 1, 2, 3, 4, 5};
    const size_t sz = 10;
    int int_arr [sz] = {};
    srand ( (unsigned)time(NULL) );   //生成随机数的种子
    std::cout << "随机生成的数组是:" << std::endl;
    for (auto &val : int_arr ) {
        val = rand() % 100;   // 获取100以内的随机数
        std::cout << val << ' ';
    }
    std::cout << std::endl;
    std::vector <int> ivec (std::begin(int_arr), std::end(int_arr));
    for (auto it = ivec.cbegin(); it != ivec.end(); ++it) 
        std::cout << *it << ' ';
    std::cout << std::endl;
}

void practice_3_42 (void)
{
    const size_t sz = 10;
    std::vector <int> ivec;
    srand ( (unsigned) time (NULL) );
    std::cout << "随机生成的vector is :" << std::endl;
    for (auto i = 0; i != sz; ++i ) {
        ivec.push_back(rand()%100);
        std::cout << ivec [i] << ' ';
    }
    std::cout << std::endl;
    std::cout << "数组内容是:" << std::endl;
    int int_arr [ivec.size()] = {};
    auto it = ivec.cbegin();
    for (auto &val : int_arr) {
        val = *it;
        ++it;
        std::cout << val << ' ';
    }
    std::cout << std::endl;
}
using int_array = int [4];

void practice_3_43 (void)
{
    int cnt = 0;
    constexpr int row_cnt = 3, col_cnt = 4;
    int int_arr [row_cnt][col_cnt] = {};
    for (int  (&row)[col_cnt] : int_arr)
        for (int & col : row) {
            col = cnt;
            ++cnt;
        }
    //利用范围for语句输出数组int_arr
    for ( int (&row)[col_cnt] : int_arr) {
        for (int col : row)
            std::cout << col << ' ';
        std::cout << std::endl;   
    }
    std::cout << std::endl;

    //利用下标输出数组int_arr
    for (int i = 0; i != row_cnt; ++i) {
        for (int j = 0; j!= col_cnt; ++j)
            std::cout << int_arr [i][j] << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //利用指针输出数组int_arr
    for (int (*p)[col_cnt] = std::begin(int_arr); p != std::end(int_arr); ++p) {
        for (int* q = std::begin(*p); q != std::end(*p); ++q)
            std::cout << *q << ' ';
        std::cout << std::endl;
    }
}

int main (int argc, char* argv[])
{
    //practice_3_2 ();
    //practice_3_4 ();
    // practice_3_5 ();
    //practice_string ();
    //practice_3_6 ();
    //practice_3_8 ();
    //practice_3_10 ();
    //practice_3_14 ();
    //practice_3_16 ();
    //practice_3_17 ();
    //practice_3_19 ();
    //practice_3_20 ();
    //practice_3_21 ();
    //practice_3_22 ();
    //practice_3_23 ();
    //practice_3_24 ();
    //practice_3_25 ();
    //practice_3_26 ();
    //practice_3_29 ();
    //practice_3_31 ();
    //practice_3_32 ();    
    //practice_3_35 ();
    //practice_3_36 ();
    //std::cout << __cplusplus << std::endl;
    //print (7.5, "hello", std::bitset <16> (377), 42);
    //practice_3_37 ();
    //practice_3_39 ();
    //practice_3_40 ();
    //practice_3_41 ();
    //practice_3_42 ();
    practice_3_43 ();

    return 0;
}



