#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {//没有存在的必要的解法
public:
    void moveone(vector<int>& vec){
        int x = vec.back();
        for(int i = vec.size() - 2; i >= 0; i--){
            vec[i + 1] = vec[i];
        }
        vec[0] = x;
    }
    void rotate(vector<int>& nums, int k) {
        for(int i = 0; i < k; i++){
            moveone(nums);
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);//括号中的反转范围是[begin, end)
        reverse(nums.begin() + k, nums.end());
    }
};