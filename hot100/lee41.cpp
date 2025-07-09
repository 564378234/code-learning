#include <vector>
#include <unordered_set>
using namespace std;

class Solution {//空间复杂度为O(n)，不满足要求
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int x = 0;
        while(set.find(x + 1) != set.end()){
            x++;
        }
        return x + 1;
    }
};

class Solutio2 {//空间复杂度为O(1)，满足要求
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){//在正确的位置代表数字x应该在nums[x - 1]上nums[x - 1] = x
            while(nums[i] <= n && nums[i] > 0 && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};