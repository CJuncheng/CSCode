#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    int n, k; cin >> n  >> k;
    string str;
    cin >> str;

    int i = 0;
    while(i < n && str[i]-'0' > k) ++i;
    str.insert(i, to_string(k));

    cout << str << endl;

    return 0;
}