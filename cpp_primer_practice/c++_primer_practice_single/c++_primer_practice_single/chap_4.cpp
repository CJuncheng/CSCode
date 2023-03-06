#include <iostream>
#include <vector>
#include <string>
#include <sys/time.h>
void practice_4_6 (void)
{
    int a = 0;
    std::cout << "Enter a int number: " ;
    std::cin >> a;
    switch (a%2) {
        case 0:     
            std::cout << "a是偶数" << std::endl;
            break;
        case 1:
            std::cout << "a是奇数" << std::endl;
            break;
        default:
            break;
    }
}

void practice_4_10 (void)
{
    int val = 0;
    std::cout << "Enter a series of :" ;
    while (std::cin >> val && val!= 42) {
        std::cout << val << std::endl;
    }
}

void practice_4_11 (void)
{
   // if (a > b && b > c && c > d)
}

void practice_4_21 (void)
{
    std::vector <int> ivec;
    size_t sz = 10;
    srand ( (unsigned) time (NULL) );
    std::cout << "数组初始值是:" << std::endl;
    for (int i = 0; i != sz; ++i ) {
        ivec.push_back (rand()%100);
        std::cout << ivec [i] << ' ';
    }
    std::cout << std::endl;
    
    for (auto& val : ivec) 
        val = (val%2 != 0) ? val*2 : val;
    std::cout << "调整后的数值:" << std::endl;
    for (std::vector<int>::const_iterator it = ivec.cbegin(); it != ivec.cend(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

void practice_4_22 (void)
{
    //condition vertion
/*    int grade = 0;
    std::cout << "Enter grade score: ";
    while (std::cin >> grade && grade >=0 && grade <= 100) {
        std::string final_grade = (grade >= 90) ? "high pass" 
                                                : (grade >= 75) ? "pass"
                                                : (grade < 60) ? "fail" : "low pass";
        std::cout << final_grade << std::endl;
    }
*/
/*
    //if vertion
    std::string final_grade;
    if (grade >= 90) {
        final_grade = "high pass";
    } else {
         if (grade >= 75) {
            final_grade = "pass";
          } else {
            if (grade < 60) 
                final_grade = "fail";
             else
                 final_grade = "low pass";
          }
    }
    std::cout << final_grade << std::endl;
*/
    int grade = 0;
    std::string final_grade;
    std::cout << "Enter grade score:" << std::endl;
    while (std::cin >> grade && grade >=0 && grade <= 100) {
        if (grade >= 90)
            final_grade = "high pass";
        else if (grade >= 75)
            final_grade = "pass";
        else if (grade <60)
            final_grade = "fail";
        else 
            final_grade = "low pass";
        std::cout << final_grade << std::endl;
    }


}

void practice_4_28 (void)
{
    using namespace std;
    cout << "类型名称\t" << "所占空间" << endl;
    cout << "bool\t\t" << sizeof (bool) << endl;    
    cout << "char\t\t" << sizeof (char) << endl;    
    cout << "wchar_t\t\t" << sizeof (wchar_t) << endl;    
    cout << "char16_t\t" << sizeof (char16_t) << endl;    
    cout << "char32_t\t" << sizeof (char32_t) << endl;    
    cout << "short\t\t" << sizeof (short) << endl;    
    cout << "int\t\t" << sizeof (int) << endl;    
    cout << "long\t\t" << sizeof (long) << endl;    
    cout << "long long\t" << sizeof (long long) << endl;    
    cout << "double\t\t" << sizeof (double) << endl;    
    cout << "long double\t" << sizeof (long double) << endl;    

}

void practice_4_37 (void)
{
    int i;
    double d;
    const std::string *ps;
    char *pc; 
    void *pv;
    pv = static_cast <void*> ( const_cast < std::string* > (ps) );
    i = static_cast <int> (*pc);
    pv = static_cast <void*> (&d);
    pc = static_cast <char *> (pv); 
}

int main (int argc, char* argv[])
{
    //practice_4_6 ();
    //practice_4_10 (); 
    //practice_4_11 ();  
    //practice_4_21 ();  
    //practice_4_22 ();    
    practice_4_28 ();    
    //practice_4_37 ();

    return 0;
}
