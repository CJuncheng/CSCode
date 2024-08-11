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
#include <bits/stdc++.h>
using namespace std;

class Test {
public:
    static int d;
    char a;
    
    short c;
    int b;
    Test(): a('a'), c(2), b(34){
    }
    virtual ~Test(){}
    static void print(void){
        cout << "hello world" << endl;
    }
    void printOut(void){
        this->print();
    }
    
};

int main(int argc, char *argv[])
{
    //int a[4] = {2, 1, 6, 8};
    //cout << *(a + 1) << endl;
    //cout << (&a) << endl;
    //int (*b)[4] = &a;

    Test test;
    test.printOut();
    cout << sizeof(test) << endl;

    return 0;
}