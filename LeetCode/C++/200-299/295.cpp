#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int, std::vector<int>, std::greater<int> > bigPQ;
    priority_queue<int, std::vector<int>, std::less<int> > smallPQ;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if(bigPQ.empty())
        {
            bigPQ.push(num);
            return;
        }

        if(bigPQ.size() == smallPQ.size())
        {
            if(smallPQ.top() < num)
            {
                bigPQ.push(num);
            }
            else
            {
                smallPQ.push(num);
            }
        }
        else if(bigPQ.size() < smallPQ.size())
        {
            if(smallPQ.top() < num)
            {
                bigPQ.push(num);
            }
            else
            {
                bigPQ.push(smallPQ.top());
                smallPQ.pop();
                smallPQ.push(num);
            }
        }
        else
        {
            if(bigPQ.top() > num)
            {
                smallPQ.push(num);
            }
            else
            {
                smallPQ.push(bigPQ.top());
                bigPQ.pop();
                bigPQ.push(num);
            }
        }
    }

    double findMedian() {
        if(smallPQ.size() == bigPQ.size())
        {
            return (double)(smallPQ.top() +  bigPQ.top()) / 2;
        }
        else if(smallPQ.size() > bigPQ.size())
        {
            return smallPQ.top();
        }
        else
        {
            return bigPQ.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    MedianFinder mf;
    mf.addNum(5);
    mf.addNum(8);
    mf.addNum(6);
    mf.addNum(7);
    cout << mf.findMedian() << endl;
    mf.addNum(3);
    cout << mf.findMedian() << endl;
    return 0;
}
