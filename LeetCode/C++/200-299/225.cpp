#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> myQueue;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        myQueue.push(x);
        int size = myQueue.size();
        for(int i = 0 ; i < size -1;++i)
        {
            myQueue.push(pop());
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = top();
        myQueue.pop();
        return temp;
    }

    /** Get the top element. */
    int top() {
        return myQueue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return myQueue.empty();
    }

};


int main()
{
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    cout << myStack.top() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.top() << endl;
    cout << myStack.empty() << endl;
    myStack.pop();
    myStack.pop();
    cout << myStack.empty() << endl;
    return 0;
}
