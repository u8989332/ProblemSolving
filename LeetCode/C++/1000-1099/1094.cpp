#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Passenger{
    int loc;
    int num;
};

bool cmp(const Passenger a, const Passenger b){
    if(a.loc != b.loc)
        return  a.loc < b.loc;
    
    return a.num < b.num;
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<Passenger> list;
        for(int i = 0 ; i < trips.size();++i){
            Passenger upPas;
            upPas.loc = trips[i][1];
            upPas.num = trips[i][0];
            list.push_back(upPas);
            
            Passenger downPas;
            downPas.loc = trips[i][2];
            downPas.num = -trips[i][0];
            list.push_back(downPas);
        }
        
        sort(list.begin(), list.end(), cmp);
        
        for(int i = 0 ; i < list.size();++i){
            capacity -= list[i].num;
            if(capacity < 0){
                return false;
            }
        }
        
        return true;
    }
};

int main()
{
    Solution s;
	vector<int> nums1{2,1,5}; 
	vector<int> nums2{3,5,7};
	vector<vector<int>> trips;
	trips.push_back(nums1);
	trips.push_back(nums2);
    cout << s.carPooling(trips, 3) << endl;

    return 0;
}
