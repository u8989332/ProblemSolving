#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
    int N;
    deque<int> myQueue;
    vector<int> myStack;
    int temp, i;
    while(cin >> N && N)
    {
        while(true)
        {
            myQueue.clear();
            myStack.clear();
            cin >> temp;
            if(temp == 0)
                break;

            myQueue.push_back(temp);
            for(i = 1 ; i < N ;++i)
            {
                cin >> temp;
                myQueue.push_back(temp);
            }

            for(i = 1 ; i <= N;++i)
            {
                myStack.push_back(i);
                while(!myStack.empty() && myQueue.front() == myStack.back())
                {
                    myQueue.pop_front();
                    myStack.pop_back();
                }
            }

            cout << (myStack.empty() ? "Yes" : "No") << endl;
        }

        cout << endl;
    }
    return 0;
}
