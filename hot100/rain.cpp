#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int flag = 0;
        int sum = 0;
        int max = 0;
        int x;
        for(int num : height){
            if (num > max){
                max = num;
            }
        }
        for(int i = 1; i <= max; i++){
            //重置flag!
            flag = 0;
            for(int j = 0; j < height.size(); j++){
                if(flag == 1 && height[j] >= i){
                    sum = sum + (j - x - 1);
                    flag = 0;
                }
                if(flag == 0 && height[j] >= i){
                    if(j < height.size() - 1){
                        if(height[j] >= i && height[j+1] >= i){
                        flag = 0;
                        }else if(height[j] >= i && height[j+1] < i){
                        flag = 1;
                        x = j;
                        }
                    }
                }
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<pair<vector<int>, int>> testCases = {
        {{0,1,0,2,1,0,1,3,2,1,2,1}, 6},   // 标准测试
        {{4,2,0,3,2,5}, 9},                 // 凹槽在两侧
        {{}, 0},                             // 空数组
        {{5}, 0},                            // 单元素
        {{1,2}, 0},                          // 两元素递增
        {{2,1}, 0},                          // 两元素递减
        {{1,0,1}, 1},                        // 简单凹槽
        {{3,0,0,0,3}, 9},                   // 多槽口
        {{5,4,3,2,1}, 0},                    // 递减序列
        {{1,2,3,4,5}, 0}                     // 递增序列
    };

    for (auto& testCase : testCases) {
        vector<int>& height = testCase.first;
        int expected = testCase.second;
        int result = sol.trap(height);
        cout << "Input: [";
        for (int i = 0; i < height.size(); i++) {
            cout << height[i];
            if (i < height.size() - 1) cout << ",";
        }
        cout << "]\n";
        cout << "Result: " << result << " | Expected: " << expected;
        cout << " | " << (result == expected ? "PASS" : "FAIL") << "\n\n";
    }

    return 0;
}