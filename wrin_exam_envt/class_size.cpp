#include <string>
#include <cstring> 
#include <iostream>

using namespace std;

class Test{

    int a;
    float b;
    double c;
};

int main(int argc, char *argv[])
{
    Test t;
    char s[] = "asddf"; 
    cout << sizeof(t) << " " << sizeof(s) << endl;
    
    return 0;
}