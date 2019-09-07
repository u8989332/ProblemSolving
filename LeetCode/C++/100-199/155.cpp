#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> myStack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        myStack.push(x);
        if(minStack.empty() || minStack.top() >= x) {
             minStack.push(x);
        }
    }

    void pop() {
        int curVal = myStack.top();
        if(curVal == minStack.top())
            minStack.pop();

        myStack.pop();
    }

    int top() {
        return myStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main()
{
    MinStack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(-1);
    myStack.push(-1);
    cout << myStack.getMin() << endl;
    cout << myStack.top() << endl;
    myStack.push(3);
    myStack.pop();
    myStack.pop();
    cout << myStack.getMin() << endl;
    cout << myStack.top() << endl;
    return 0;
}
