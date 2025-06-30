#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        while(right < n){
            if(nums[right] != 0){
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};