#include <iostream>
#include <map>
#include <string>
using namespace std;


void printKey1(map<string, string>& m)
{
    cout << m["key1"] << endl;
}

int main()
{
    map<string,string>m;
    m["key1"] = "value1";
    m["key1"] = "new value1";
    m["key2"] = "value2";
    printKey1(m);
}