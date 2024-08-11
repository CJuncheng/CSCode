

#include <iostream>
#include <vector>

#include <semphore>

//创建生产者条件变量
sem1 = 8;
//创建消费者变量
sem2 = 0;
// 创建全局变量
vec;

void product(int val){
    sem1.         //生产者条件变量 - 1
    vec.push_back(val);
    sem2.         // 消费者条件变量 + 1
}

void custom(void){
    sem2.         //消费者条件变量 - 1
    vec.pop_back();
    sem1.        // 生产者条件变量 + 1
}

int main(int argc, char* argv[]){
    
    return 0;
}