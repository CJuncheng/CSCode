
#include <iostream>
using namespace std;

class Parent{
public:
    Parent(){
        print();
    }

    virtual void print(){
        cout << "Parent constructor" << endl;
    }

    virtual ~ Parent(){
        print();
    }
};

class Child : public Parent{
public:
    Child(){
        print();
    }

    void print() override{
        cout << "Child constructor" << endl;
    }

    ~Child() override{
        print();
    }
};

int main(){
    Parent*obj = new Child();
    delete obj;
    return 0;
}