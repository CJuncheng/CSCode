#include <iostream>

template<typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
    };

    Node* front;
    Node* back;
    int size_;

public:
    Deque() : front(nullptr), back(nullptr), size_(0) {}

    ~Deque() {
        while (!isEmpty()) {
            pop_front();
        }
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    int size() const {
        return size_;
    }

    void push_front(const T& data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size_++;
    }

    void push_back(const T& data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }
        size_++;
    }

    void pop_front() {
        if (isEmpty()) {
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        } else {
            back = nullptr;
        }
        delete temp;
        size_--;
    }

    void pop_back() {
        if (isEmpty()) {
            return;
        }
        Node* temp = back;
        back = back->prev;
        if (back) {
            back->next = nullptr;
        } else {
            front = nullptr;
        }
        delete temp;
        size_--;
    }

    void clear(){
        while (!isEmpty()) {
            pop_front();
        }
        size_ = 0;
    }
/*
    T& getFront() const {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty");
        }
        return front->data;
    }

    T& getBack() const {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty");
        }
        return back->data;
    }
*/
};

/*
int main() {
    Deque<int> deque;
    deque.push_front(1);
    deque.push_back(2);
    deque.push_front(3);
    deque.push_back(4);

    std::cout << "Front: " << deque.getFront() << std::endl;
    std::cout << "Back: " << deque.getBack() << std::endl;

    deque.pop_front();
    deque.pop_back();

    std::cout << "Front: " << deque.getFront() << std::endl;
    std::cout << "Back: " << deque.getBack() << std::endl;

    return 0;
}
*/