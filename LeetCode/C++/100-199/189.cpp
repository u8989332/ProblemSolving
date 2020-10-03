#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if((k % n)== 0){
            return;
        }
        
        k = k % n;
        int temp1, temp2;
        int counts = 0;
        for(int start = 0 ; counts < n;++start){
            int current = start;
            temp1 = nums[start];
            do{
                int next = (current + k) % n;
                temp2 = nums[next];
                nums[next] = temp1;
                temp1 = temp2;
                current = next;
                counts++;
            }while(current!= start);
        }
    }
};

int main() {
	Solution sol;
	vector<int> nums{1,2,3,4,5,6,7};
	sol.rotate(nums, 3);
	for(int i = 0 ; i < nums.size();++i){
		cout << " " << nums[i];
	}
	return 0;
}