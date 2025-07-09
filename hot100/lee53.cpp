#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0], cur = 0;
        if(nums.size() == 1)return nums[0];
        for(int x : nums){
            cur = max(x, cur + x);//如果之前的值是减少，就会被舍去
            maxsum = max(cur, maxsum);//取当前值与历史最大值的最大值
        }
        return maxsum;
    }
};