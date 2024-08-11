#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int arr[5]; 
    int a1 = sizeof(arr);
    cout << a1 << endl;

    int* ptr; int a2 = sizeof(ptr);
    cout << a2 << endl;

    class A{ int a; }; int a3 = sizeof(A);
    cout << a3 << endl;
    class A{static int a; int b;};
    

    //sizeof(A);
s

    return 0;
}