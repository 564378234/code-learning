# include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> map;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(map.find(nums[i]) != map.end()){
                return {map[nums[i]], i};
            }
            map[target - nums[i]] = i;
        }
        return {};
    }
};