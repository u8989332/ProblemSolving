#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
priority_queue<LL, vector<LL>, greater<LL> >pq;
set<LL> s;
const int coef[3] = {2,3,5};
int main()
{
    pq.push(1);
    s.insert(1);
    for(int i = 1;;++i)
    {
        LL topSmall = pq.top();
        pq.pop();
        if(i == 1500)
        {
            cout << "The 1500'th ugly number is " << topSmall << "." << endl;
            break;
        }

        for(int j = 0 ; j < 3;++j)
        {
            LL newN = topSmall * coef[j];
            if(!s.count(newN))
            {
                pq.push(newN);
                s.insert(newN);
            }
        }
    }
    return 0;
}
