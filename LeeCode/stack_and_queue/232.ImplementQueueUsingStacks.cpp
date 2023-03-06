#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;
public:
    MyQueue() {

    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int res = outStack.top();
        outStack.pop();
        return res;
    }
    
    int peek() {
        int res = this->pop();
        outStack.push(res);
        return res;

    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};


int main (int argc, char* argv[])
{
    MyQueue que;
    que.push(1);
    que.push(2);
    cout << que.peek() << endl;  // 返回 1
    cout << que.pop() << endl;   // 返回 1
    cout << que.empty() << endl;
    
    return 0;
}