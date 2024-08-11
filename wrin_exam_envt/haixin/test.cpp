
#include <iostream>
#include <cstring>

using namespace std;

class Base{
public:
Base(){ std::cout <<"P";}
~Base(){std::cout <<"p"; }
};

class Sub : public Base{

public:

Sub() { std::cout <<"S"; }
~Sub() {std::cout <<"s"; }
private:
    Base b;
};



int main(int argc, char* argv[])
{
    char* p  = new char[100];
    int a = sizeof(p);
    cout << a << endl;
    return 0;
}