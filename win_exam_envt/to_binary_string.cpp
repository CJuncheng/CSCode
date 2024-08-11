#include <string>
#include <cstring> 
#include <iostream>

using namespace std;

inline string toBinaryStr(int a){
    string s = "";
    while(a){
        if(a%2==0) s = '0' + s;
        else s = '1' + s;
        a /= 2;
    }
    return s;
}

int main(int argc, char *argv[])
{
    int i = 4;
    string tmp_str = toBinaryStr(i);

    cout << tmp_str << endl;
    
    return 0;
}