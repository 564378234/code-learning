using namespace std;
#include<vector>
#include<iostream>

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
            while (left<=right)
            {
                int mid = left + ((right-left)>>1);
                if (nums[mid]>target)
                {
                    right = mid - 1;
                } else if (nums[mid]<target)
                {
                    left = mid + 1;
                }else {
                    return mid;
                }
            }
            return -1;
        }
    };

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 5;

    int result = sol.search(nums, target);
    cout << "Index of " << target << " is: " << result << endl;

    return 0;
}