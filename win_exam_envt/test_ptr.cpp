#include <iostream>
using namespace std;


int main(int argc, char* argv[]){
    int a[3] = {1, 2};
    int (*p)[3] = &a; 
    cout << p+1 << " " << a+1 << endl;
    
}