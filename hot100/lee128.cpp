#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> set1(nums.begin(), nums.end());//这步时间复杂度为nlogn
        vector<int> curnums(set1.begin(), set1.end());
        int n = curnums.size();
        int fast = 0, slow = 0, result = 0;
        int curcount;
        if(n == 1){
            result = 1;
            return result;
        }
        for(; fast < n; fast++){
            if(fast == 0)continue;
            if(curnums[fast] - curnums[fast - 1] != 1){
                curcount = fast - slow;
                slow = fast;
                if(result < curcount)result = curcount;
            }
            if(fast == n - 1 && curnums[fast] - curnums[fast - 1] == 1){
                curcount = fast - slow + 1;
                slow = fast;
                if(result < curcount)result = curcount;
            }
        }
        return result;
    }
};

class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set1(nums.begin(), nums.end());
        int result = 0;
        int count = 1;
        for(int num : set1){
            int cur = num;
            if(set1.find(cur - 1) == set1.end()){
                while(set1.find(cur + 1) != set1.end()){
                    count += 1;
                    cur += 1;
                }
                // if(count > result)result = count;//下一行更简洁
                result = max(count, result);
                count = 1;
            }
        }
        return result;
    }
};