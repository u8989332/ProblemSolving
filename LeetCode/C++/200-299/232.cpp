#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> bufferStack;
    stack<int> myStack;
    void transferToBuffer(){
        while(!myStack.empty())
        {
            bufferStack.push(myStack.top());
            myStack.pop();
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        myStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(bufferStack.empty()) {
             transferToBuffer();
        }

        int top = bufferStack.top();
        bufferStack.pop();
        return top;
    }

    /** Get the front element. */
    int peek() {
        if(bufferStack.empty()) {
            transferToBuffer();
        }

        return bufferStack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return myStack.empty() && bufferStack.empty();
    }
};

int main()
{
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    cout << myQueue.peek() << endl;
    cout << myQueue.pop() << endl;
    cout << myQueue.peek() << endl;
    cout << myQueue.empty() << endl;
    myQueue.pop();
    myQueue.pop();
    cout << myQueue.empty() << endl;
    return 0;
}
