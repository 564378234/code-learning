#include <iostream>
#include <vector>
#include <algorithm>//有sort函数
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 3)return result;
        int i = 0, j = 1, k = n - 1;
        int sum = nums[i] + nums[j] + nums[k];
        if(n == 3){//似乎这个是多余的，在下面可以直接包含
            if(sum != 0){
                return result;
            }else {
                result.push_back({nums[i], nums[j], nums[k]});
                return result;
            }
        }
        while(i < n - 2){
            j = i + 1;
            k = n - 1;
            while(j < k){
                sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    result.push_back({nums[i], nums[j], nums[k]});
                    //两个while去重的结果是仍然指向相同的数字，但是重复的已经被去除
                    while(j < k && nums[j] == nums[j + 1])j++;
                    while(j < k && nums[k] == nums[k - 1])k--;
                    //只移动一位一定会让sum不为0，所以要j和k要一起移动
                    j++;
                    k--;
                }else if(sum < 0){
                    j++;
                }else{
                    k--;
                }
            }
            //对于i的去重,while的原理与j和k相同
            while(i < n - 2 && nums[i] == nums[i + 1])i++;
            i++;
        }
        return result;
    }
};