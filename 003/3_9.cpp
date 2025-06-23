#include <iostream>
#include <vector>
#include <algorithm>//有sort函数
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 4){
            return result;
        }
        int a = 0, d = n - 1;
        while(a < n - 3){
            //放在这里会出错int b = a + 1;
            d = n - 1;//d要被重置
            while(d > a + 2){
                int b = a + 1;//要放在这个循环位置，d重置之后需要重新定义b和c
                int c = d - 1;
                while(b < c){
                    long sum = (long)nums[a] + nums[b] + nums[c] + nums[d];//超出int范围会报错
                    if(sum == target){
                        result.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while(b < c && nums[b] == nums[b + 1])b++;
                        while(b < c && nums[c] == nums[c - 1])c--;
                        b++;
                        c--;
                    }else if(sum > target){
                        c--;
                    }else{
                        b++;
                    }
                }
                while(d > a + 2 && nums[d] == nums[d - 1])d--;
                d--;
            }
            while(a < n - 3 && nums[a] == nums[a + 1])a++;
            a++;
        }
        return result;
    }
};