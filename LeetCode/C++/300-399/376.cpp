#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2){
            return nums.size();
        }
        
        const int BEGIN = 0;
        const int UP = 1;
        const int DOWN = 2;
        int curState = BEGIN;
        int maxLength = 1;
        for(int i = 1;i < nums.size() ; ++i){
            switch(curState){
                case BEGIN:
                    if(nums[i-1] > nums[i]){
                        curState = DOWN;
                        maxLength++;
                    }
                    else if(nums[i-1] < nums[i]){
                        curState = UP;
                        maxLength++;
                    }
                    break;
                case UP:
                    if(nums[i-1] > nums[i]){
                        curState = DOWN;
                        maxLength++;
                    }
                    break;
                case DOWN:
                    if(nums[i-1] < nums[i]){
                        curState = UP;
                        maxLength++;
                    }
                    break;
            }
        }
        
        return maxLength;
    }
};

int main()
{
    Solution s;
	vector<int> nums{1,17,5,10,13,15,10,5,16,8}; 
    cout << s.wiggleMaxLength(nums) << endl;

    return 0;
}
