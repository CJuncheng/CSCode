#include <thread>
#include <iostream>
#include <vector>

void worker(){
    std::thread::id tid = std::this_thread::get_id();
    std::cout << "thread id is: " << tid << std::endl;
} 

int main(int argc, char* argv[]){
    const int thread_num = 8;

    std::vector<std::thread> threads;

    for(int i = 0; i < thread_num; ++i)
        threads.push_back(worker);
    for(int i = 0; i < thread_num; ++i)
        threads[i].join();

    std::cout << "threads is over!" << std::endl;
    
    return 0;
}