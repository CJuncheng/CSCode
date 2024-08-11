#include <iostream>
#include <vector>
#include <map>
#include <cctype> // tolower()
#include <utility> // pair
#include <unordered_map>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <initializer_list>
#include <cstring>
using namespace std;


class A {
    char a;
    double b;
    int c;
    virtual void d() {}
    virtual void d2() {}
};

int main(int argc, char *argv[])
{
    A a;
    cout << sizeof(a) << endl;
    
    return 0;
}

