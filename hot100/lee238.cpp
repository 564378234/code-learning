#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        //vector<int> left, right;//一个记录当前位置左侧所有元素乘积，一个记录右侧所有元素乘积，最后两个乘积相乘得到结果但是空间复杂度位o(n)
        int x = 1, n = nums.size();//用answer存储left，再倒序遍历一遍只使用o(1)记录倒序遍历乘积
        answer.push_back(1);
        for(int i = 1; i < n; i++){
            answer.push_back(answer[i - 1] * nums[i - 1]);
        }
        for(int i = n - 1; i >= 0; i--){
            answer[i] = answer[i] * x;
            x = x * nums[i];
        }
        return answer;
    }
};