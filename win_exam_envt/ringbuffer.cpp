#include <iostream>

class RingBuffer{
private:
    int* buffer;
    int capacity;
    int size;
    int head;
    int tail;

public:
    RingBuffer(int capacity_) {
        this->buffer = new int[capacity_];
        this->capacity = capacity_;
        this->size = 0;
        this->head = 0;
        this->tail = 0;
    }
    ~RingBuffer() {
        delete[] buffer;
    }

    void add(int item){
        if(size < capacity){
            buffer[tail] = item;
            tail = (tail+1) % capacity;
            ++size;
        } else {
            std::cout << "缓冲区已满，无法添加元素" << std::endl;
        }
    }

    int remove(){
        if(size > 0) {
            int item = buffer[head];
            head = (head+1)%capacity;
            --size;
            return item;
        } else {
            std::cout << "缓冲区为空，无法移除元素。" << std::endl;
        }
    }

    int getSize(){ return size; }
    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == capacity;
    }
};

int main(int argc, char* argv[]){
    RingBuffer buffer(5);

    buffer.add(1);
    buffer.add(2);
    buffer.add(3);
    buffer.add(4);
    buffer.add(5);

    std:: cout << "缓冲区大小：" << buffer.getSize << std::endl;
    std:: cout << "移除元素：" << buffer.remove << std::endl;

    return 0;

}