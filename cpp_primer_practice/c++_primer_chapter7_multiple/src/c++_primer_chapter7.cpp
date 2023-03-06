#include <iostream>
#include <vector>
#include "Sales_item.h"
#include "Sales_data_7_2.h"

void practice_7_2 (void)
{
    std::cout << "请输入交易记录（ISBN、销售量、原价、实际售价）：" << std::endl;
    SalesData72 total;
   /* if (std::cin >> total) {

 
    } else {
        std::cerr << "No data?!" << std::endl;
    }*/

}
/*
//practice_7_5
class Person
{
    public:
        std::string getName (void) const { return name; }
        std::string getAddress (void) const { return address;}
        std::istream& read (std::istream& is, Person& per)
        {
            is >> per.name >> per.address;
            return is;
        }
        std::ostream& print (std::ostream& os, const Person& per)
        {
            os << per.getName << per.getName;
            return os;
        }
    public:
        Person () = default;
        Person (const std::string& na, const std::string& add)
        {
            name = na;
            address = add;
        }
        //Person (std::istream &is) {is >> *this;}
    private:
        std::string name;
        std::string  address;
};
*/
//practice_7_6
SalesData72 add (const SalesData72& lhs, const SalesData72& rhs) //不允许返回局部变量的引用和指针，局部变量的返回只能拷贝
{
    SalesData72 sum = lhs;
    sum.combine (rhs);
    return sum;
}
/*
std::istream read (std::istream& is, SalesData72& item)
{
    is >> item.bookNO >> item.unites_sold >> item.selling_price >> item.sale_price;
    return is;
}
std::ostream print (std::ostream& os, const SalesData72& item)
{
    os << item.bookNO << " " << item.unites_sold << " " << item.selling_price << " " << item.sale_price << " " << item.discount;
    return os;
}
*/

//practice_7_18
/*
封装是指保护类的成员不被随意访问的能力。通过把类的实现细节设置为private，
我们就能完成类的封装。封装实现了类的接口和实现的分离。
封装有两个重要优点：一是确保用户代码不会无意间破坏封装对象的状态；二是
被封装的类的具体实现细节可以随时改变，而且无须调整用户级别代码
*/

//practice_7_20
/*
非成员函数访问类的私有成员，我们可以把它声明成该类的友元，但但是友元破坏程序封装性
*/

/*
//practice_7_24
class Screen 
{
    public:
        Screen () = default;
        Screen (unsigned ht, unsigned wt) : height (ht), width (wt), contents (ht*wt, ' ') {}
        Screen (unsigned ht, unsigned wt, char c) : height(ht), width(wt), contents(ht * wt, c) {}

    private:
        unsigned height = 0,width = 0;
        unsigned cursor = 0;
        std::string contents;

}
*/
//practice_7_26
//类内定义函数算隐式内联，

/*
//practice_7_27
class Screen
{
public:
    Screen() = default;
    Screen(unsigned ht, unsigned wt) : height(ht), width(wt), contents(ht * wt, ' ') {}
    Screen(unsigned ht, unsigned wt, char c) : height(ht), width(wt), contents(ht * wt, c) {}
public:
    Screen& move (unsigned r, unsigned c)
    {
        cursor = r * width + c;
        return *this;
    }
    Screen& set (char ch)
    {
        contents [cursor] = ch;
        return *this;
    }
    Screen &set(unsigned r, unsigned c, char ch)
    {
        contents[r * width + c] = ch;
        return *this;
    }
    Screen& display ()
    {
        std::cout << contents << std::endl;
        return *this;
    }
private:
    unsigned height = 0, width = 0;
    unsigned cursor = 0;
    std::string contents;

};
*/
//practice_7_31
class X; //不完类型，可以定义不完全类型的指针，但不能创建不完全类型的对象 
class Y
{
    X* x;
};
class X
{
    Y y;
};

//practice_7_32
class WindowMgr
{
    public:
        void clear (void);
};
class Screen
{
    friend void WindowMgr::clear(void);
public:
    Screen() = default;
    Screen(unsigned ht, unsigned wt) : height(ht), width(wt), contents(ht * wt, ' ') {}
    Screen(unsigned ht, unsigned wt, char c) : height(ht), width(wt), contents(ht * wt, c) {}

private:
    unsigned height = 0, width = 0;
    unsigned cursor = 0;
    std::string contents;
};

void
WindowMgr::clear(void)
{
    Screen myScreen(5, 5, 'X');
    std::cout << "before: " << myScreen.contents << std::endl;
    myScreen.contents = " ";
    std::cout << "after:" << myScreen.contents << std::endl;
}

main(int argc, char *argv[])
{
	
    //SalesData72 ite;
    /*
    //practice_7_27;
    Screen myScreen(5,5,'X');
    myScreen.move(4, 0).set('#').display();
    std::cout << std::endl;
    */
   WindowMgr cl;
   cl.clear();
    return 0;
}
