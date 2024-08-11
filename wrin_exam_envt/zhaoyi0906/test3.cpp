#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;
int cout = 0;

void increaseA() {
    for (int i = 0; i < 10; ++i) {
        mtx.lock();
        cout += 2;
        mtx.unlock();
    }
}

void decreaseB() {
    for (int i = 0; i < 10; ++i) {
        mtx.lock();
        cout -= 2;
        mtx.unlock();
    }
}

void increaseC() {
    for (int i = 0; i < 10; ++i) {
        mtx.lock();
        cout += 3;
        mtx.unlock();
    }
}

int main() {
    thread Athread(increaseA);
    thread Bthread(decreaseB);
    thread Cthread(increaseC);

    Athread.join();
    Bthread.join();
    Cthread.join();

    std::cout << "The final cout value is: " << cout << std::endl;

    return 0;
}