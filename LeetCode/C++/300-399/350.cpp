#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        for(int i = 0, j = 0;i < nums1.size() && j < nums2.size();){
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        
        return ans;
    }
};

int main() {
	Solution sol;
	vector<int> nums1{1,2,2,1};
	vector<int> nums2{2,2};
	vector<int> ans = sol.intersect(nums1, nums2);
	for(int num : ans){
		cout << num << " ";
	}
	return 0;
}