#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int quickSelect(vector<int>& nums, int k, int left, int right)
    {
        int pivot = nums[left];
        int i = left;
        int j = right;
        while(i <= j)
        {
            while(nums[i] > pivot)
            {
                i++;
            }

            while(nums[j] < pivot)
            {
                j--;
            }

            if(i <= j)
            {
                swap(nums, i, j);
                i++;
                j--;
            }
        }

        if(left < j && k <= j)
            return quickSelect(nums, k, left, j);

        if(i < right && k >= i)
            return quickSelect(nums, k, i, right);

        return nums[k];
    }

    void swap(vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k - 1, 0, nums.size() - 1);
    }
};

int main()
{
    vector<int>nums = {4,1,6,5,9,2};
    Solution s;
    cout << s.findKthLargest(nums, 2) << endl;
    return 0;
}
