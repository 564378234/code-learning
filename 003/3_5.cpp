#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

// class Solution{
//     public:
//         vector<int> twoSum(vector<int>& nums, int target){//这个时间复杂度是n^2
//             unordered_set<int> set(nums.begin(), nums.end());
//             for(int i = 0; i < nums.size(); i++){
//                 int x = target - nums[i];
//                 if(set.find(x) != set.end()){//只要找到就会进入此循环
//                     for(int j = 0; j < nums.size(); j++){
//                         if(x == nums[j] && i != j){//在这里再判断是否是同一下标
//                             return vector<int>{i,j};
//                         }
//                     }
//                 }
//             }
//             return vector<int>{};
//         }
// };

class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target){//使用unordered_map让时间复杂度降低到n
            unordered_map<int, int> map;
            for(int i = 0; i < nums.size(); i++){
                int x = target - nums[i];
                if(map.find(x) != map.end()){
                    return vector<int>{i, map[x]};
                }
                map[nums[i]] = i;
            }
            return vector<int>{};
        }
};

// 辅助函数：打印vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if(i != vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    
    // 测试用例1：普通情况
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(nums1, target1);
    cout << "测试用例1 [2,7,11,15], target=9: ";
    printVector(result1);
    cout << endl;
    
    // 测试用例2：有重复元素
    vector<int> nums2 = {3, 2, 5, 3};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);
    cout << "测试用例2 [3,2,5,3], target=6: ";
    printVector(result2);
    cout << endl;
    
    // 测试用例3：无解情况
    vector<int> nums3 = {1, 2, 3, 4};
    int target3 = 10;
    vector<int> result3 = sol.twoSum(nums3, target3);
    cout << "测试用例3 [1,2,3,4], target=10: ";
    printVector(result3);
    cout << endl;
    
    // 测试用例4：相同元素相加
    vector<int> nums4 = {3, 3};
    int target4 = 6;
    vector<int> result4 = sol.twoSum(nums4, target4);
    cout << "测试用例4 [3,3], target=6: ";
    printVector(result4);
    cout << endl;
    
    return 0;
}