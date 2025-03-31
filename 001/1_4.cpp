// 1.4有序数组的平方
using namespace std;
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            for (int i = 0; i < nums.size(); i++){
                nums[i] *= nums[i];
            }
            sort(nums.begin(), nums.end());
            return nums;
        }
    };

class Solution02 {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int right = nums.size() - 1;
            int n = nums.size() - 1;
            vector<int> result(nums.size(), 0);// 创建一个新数组存储结果
            for (int left = 0; left <= right; left++) {
                if (nums[left] * nums[left] < nums[right] * nums[right]){
                    result[n] = nums[right] * nums[right];
                    right--;
                    left--;
                } else {
                    result[n] = nums[left] * nums[left];
                }
                n--;
            }
            return result;
        }
};

int main() {
    vector<int> nums = {-4,-1,0,3,10};// 直接调用数组会直接更改数组，sol.sortedSquares(nums);执行完nums也变
    vector<int> nums02 = {-4,-1,0,3,10};
    Solution sol;
    Solution02 sol02;
    vector<int> result = sol.sortedSquares(nums);
    vector<int> result02 = sol02.sortedSquares(nums02);
    cout << "result:";
    for (int i : result) {// 定义一个临时变量 i，每次循环时从 result 中取出一个元素赋值给它
        cout << i << " ";
    }
    cout << endl;
    cout << "result02:";
    for (int i : result02) {// 定义一个临时变量 i，每次循环时从 result 中取出一个元素赋值给它
        cout << i << " ";
    }
    cout << endl;

    return 0;
}