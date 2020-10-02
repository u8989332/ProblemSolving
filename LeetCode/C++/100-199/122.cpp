#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxAns = 0;
        for(int i = 1 ; i < prices.size();++i){
            if(prices[i] > prices[i-1]){
                maxAns += prices[i] - prices[i-1];
            }
        }
        
        return maxAns;
    }
};

int main() {
	
	vector<int> prices{7,1,5,3,6,4};
	Solution sol;
	cout << sol.maxProfit(prices) << endl;
	return 0;
}