#include <iostream>
//#include "Sales_item.h"
void practice_1_17 (void)
{
    int currVal = 0, val = 0;
    std::cout << "Please input number quence:"; 
    if (std::cin >> currVal)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if (val == currVal)
                ++cnt;
            else 
            {
                std::cout << currVal << " occurs " 
                          << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << "while xunhuan jieshu" << std::endl;
        std::cout << currVal << " occurs " 
                  << cnt << " times" << std::endl;
    }
}

void practice_1_20 (void)
{


}

int main (int argc, char* argv[])
{
    practice_1_17();
    return 0;
}
