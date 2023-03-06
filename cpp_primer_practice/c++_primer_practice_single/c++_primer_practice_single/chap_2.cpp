#include <iostream>
#include <typeinfo>
void practice_2_3 (void)
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u-i << std::endl;
}

void practice_2_8 (void)
{
    std::cout << "2\x4d\012";
    std::cout << "2\tM\n";
}

void practice_2_18 (void)
{
    int a = 0, b = 56, *p1 = nullptr;
    p1 = &a;
    std::cout << "p1 ptr :" << p1 << " " << &b << " " << "a:" << a << std::endl;
    *p1 = b;
    std::cout << a << std::endl;
    p1 = &b;
    std::cout << p1 << std::endl;
}

void practice_2_34 (void)
{
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;
    std::cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << g << std::endl;
    a = 42; b = 42; c = 42;// d = 42; e = 42; g = 42; 
    std::cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << g << std::endl;
}

void practice_2_35 (void)
{
    const int i = 42;
    auto j = i;// j是整数;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    std::cout << typeid(i).name() << std::endl;
    std::cout << typeid(j).name() << std::endl;
    std::cout << typeid(k).name() << std::endl;
    std::cout << typeid(p).name() << std::endl;
    std::cout << typeid(j2).name() << std::endl;
    std::cout << typeid(k2).name() << std::endl;
}

void practice_2_36 (void)
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype( (b) ) d = a;
    ++c;
    ++d;
    std::cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << std::endl;
}

void practice_2_40 (void)
{
    struct SalesData {
        std::string bookNo;
        unsigned uints_sold = 0;
        double sellingprice = 0.0;
        double saleprice = 0.0;
        double discount = 0.0;
    };
}

int main(int argc, char* argv[])
{
//  practice_2_3 ();
//  practice_2_8 ();
//  practice_2_18 ();
//  practice_2_34 ();
//  practice_2_35 ();
//  practice_2_36 ();
    //SalesData salesdata;
    //salesdata.sellingprice = 178.6;
    
    return 0;
}
