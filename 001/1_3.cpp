using namespace std;
#include <vector>
#include <iostream>

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int last = 0;
            for(int fast = 0;fast < nums.size();fast++){
                if(nums[fast] != val){
                    nums[last] = nums[fast];
                    last++;
                }
            }
            return last;
        }
    };

class Solution02 {
    public:
        int removeElement(vector<int>& nums, int val) {
            int k = 0;
            for(int i = 0;i < nums.size();i++){
                if(nums[i] != val){
                    nums[i - k] = nums[i];
                }else {
                    k++;
                }
            }
            return nums.size() - k;
        }
    };

int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};// 如果两个调用都使用同一个nums会导致第二个传入的nums被改变
    vector<int> nums02 = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution s;
    Solution02 s02;
    int result = s.removeElement(nums,val);
    int result02 = s02.removeElement(nums02,val);
    cout << result << endl;
    cout << result02 << endl;
}