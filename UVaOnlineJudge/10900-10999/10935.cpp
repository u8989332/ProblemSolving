#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    deque<int> d;
    while(cin >> n && n)
    {
        d.clear();
        for(int i = 1; i <= n;++i)
        {
            d.push_back(i);
        }

        cout << "Discarded cards:";
        bool firstDiscardPrint = false;
        while(d.size() > 1){
            int discard = d.front();
            d.pop_front();
            if(firstDiscardPrint){
                cout << ",";
            }
            cout << " " << discard;

            int nextTop = d.front();
            d.pop_front();
            d.push_back(nextTop);
            firstDiscardPrint = true;
        }

        cout << endl;

        cout << "Remaining card: " << d.front() << endl;
    }
    return 0;
}
