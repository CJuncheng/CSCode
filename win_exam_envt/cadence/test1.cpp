#include <iostream>
using namespace std;
#include <iostream>
using namespace std;


class Base
{
public:
   virtual void func()
   {
      cout <<"Base\n";
   }
};

class Derv : public Base
{
public:
   void func(){
      cout << "Derv\n";
   }
};

void f1(Base*b){
   b->func();
}

void f2(Base&b)
{
   b.func();
}

void f3(Base b){
   b.func();
}


int main(void)
{
   Derv d;
   f1(&d);
   f2(d);
   f3(d);

   return 0;
}