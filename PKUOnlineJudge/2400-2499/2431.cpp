#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Stop{
	int dist, amount;
};

bool cmp(const Stop &a, const Stop &b)
{
    return a.dist < b.dist;
}

int main() {
	int n;
	Stop stops[10005];
	int L, curAmount;
	while(cin >> n){
		int ans = 0;
		bool notToTown = false;
		priority_queue<int, vector<int>, less<int> > q;
		for(int i = 0 ; i < n;++i){
			cin >> stops[i].dist >> stops[i].amount;
		}

		cin >> L >> curAmount;
		
		
		stops[n].dist = 0;
		stops[n].amount = 0;
		
		sort(stops, stops + (n+1), cmp);
		
		int curLength = L;
		
		for(int i = n ; i >= 0;--i){
			int curDistance = curLength - stops[i].dist;
			
			while(curAmount - curDistance < 0){
				if(q.empty()){
					notToTown = true;
					break;
				}else{
					curAmount += q.top();
					q.pop();
					ans++;
				}
			}
			
			curAmount -= curDistance;
			q.push(stops[i].amount);
			curLength = stops[i].dist;
		}
		
		if(notToTown){
			cout << "-1" << endl;
		}
		else{
			cout << ans << endl;
		}
	}
	return 0;
}