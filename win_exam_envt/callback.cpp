
#include <iostream>

void callbackFunc(void) {
    std::cout << "This is callback function" << std::endl;
}

void callbackExev(void (*fp)()){
    fp();
}

int main(int argc, char* argv[])
{
    callbackExev(callbackFunc);
    return 0;
}