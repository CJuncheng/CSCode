#include <iostream>
using namespace std;
enum class Name{
    Meng,Chuan = 3, Liu,Wang,
};

int main(int argc, char* argv[]) {
    int a[21][3] = {{1,2,3}, {4,5,6}};
    int m, *p = &a[0][0];
    m=(*p)*(*(p+2))*(*(p+4));
    cout << m << endl;
    return 0;
}
