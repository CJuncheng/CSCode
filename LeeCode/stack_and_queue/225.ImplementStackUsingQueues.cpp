#include <queue>
#include <iostream>
using namespace std;

class MyStack {
    /*
private:
    queue<int> queue1; //主队列
    queue<int> queue2; //辅队列
public:
    MyStack() {

    }
    
    void push(int x) {
        queue1.push(x);
    }
    
    int pop() {
        int len = queue1.size();
        --len;
        while(len--) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int res = queue1.front();
        queue1.pop();
        queue1 = queue2;
        while(!queue2.empty()) queue2.pop();
        return res;
    }
    
    int top() {
        return queue1.back();
    }
    
    bool empty() {
        return queue1.empty();
    }
    */
private:
    queue<int> queue; //主队列
public:
    MyStack() {

    }
    
    void push(int x) {
        queue.push(x);
    }
    
    int pop() {
        int len = queue.size();
        --len;
        while(len--) {
            queue.push(queue.front());
            queue.pop();
        }
        int res = queue.front();
        queue.pop();
        return res;
    }
    
    int top() {
        return queue.back();
    }
    
    bool empty() {
        return queue.empty();
    }
};

int main (int argc, char* argv[])
{
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout << myStack.pop() << endl;   // 返回 1
    
    return 0;
}