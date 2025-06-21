#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
            unordered_set<int> set1(nums1.begin(), nums1.end());
            unordered_set<int> result;
            for(int num : nums2){
                if(set1.find(num) != set1.end()){
                    result.insert(num);
                }
            }
            // vector<int> resultvector(result.begin(), result.end());
            // return resultvector;

            return vector<int>(result.begin(), result.end());//简洁写法
        }
};

// 打印 vector 内容
void printVector(const vector<int>& nums) {
    cout << "[";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> res1 = sol.intersection(nums1, nums2);
    cout << "Test Case 1: ";
    printVector(res1);  // 预期输出 [2]

    // 测试用例 2
    vector<int> nums3 = {4, 9, 5};
    vector<int> nums4 = {9, 4, 9, 8, 4};
    vector<int> res2 = sol.intersection(nums3, nums4);
    cout << "Test Case 2: ";
    printVector(res2);  // 预期输出 [9, 4]（顺序可能不同）

    // 测试用例 3（无交集）
    vector<int> nums5 = {1, 2, 3};
    vector<int> nums6 = {4, 5, 6};
    vector<int> res3 = sol.intersection(nums5, nums6);
    cout << "Test Case 3: ";
    printVector(res3);  // 预期输出 []

    return 0;
}
