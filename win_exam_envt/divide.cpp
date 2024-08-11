#include <iostream>

int divide(int dividend, int divisor) {
    if (divisor == 0) {
        throw std::runtime_error("divisor can not be 0");
    }
    return dividend / divisor;
}

int main() {
    int dividend = 2, divisor = 0;
    try {
        int result = divide(dividend, divisor);
        std::cout << "resule is : " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "exception is: " << e.what() << std::endl;
    }
    return 0;
}