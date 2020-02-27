#include <iostream>
#include <queue>
#include <vector>
#define ll long long
using namespace std;

int main()
{

    int N;
    ll ans;
    ll t;
    priority_queue<ll,vector<ll>,greater<ll> > pq;
    while(cin >> N)
    {
        ans = 0;
        for(int i = 0 ; i < N;++i)
        {
            cin >> t;
            pq.push(t);
        }

        while(pq.size() > 1)
        {
            ll t1 = pq.top();
            pq.pop();
            ll t2 = pq.top();
            pq.pop();
            ll cur_sum = t1 + t2;
            ans += cur_sum;
            pq.push(cur_sum);
        }


        cout << ans << endl;

    }
    return 0;
}