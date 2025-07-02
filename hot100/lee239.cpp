#include <vector>
#include <deque>
using namespace std;

class Solution {//超时
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        int maxnum = nums[0], n = nums.size(), cur;
        vector<int> result;
        if(n == 1)return vector<int>{maxnum};//vector<int>{maxnum}和vector<int>(maxnum)有什么区别
        for(int i = 0; i < k; i++){
            deq.push_back(nums[i]);
            maxnum = max(maxnum, nums[i]);
        }
        result.push_back(maxnum);
        for(int i = 0; i < n - k; i++){
            if(nums[i + k] > maxnum){//如果新加入的数大于当前最大值，那新元素一定是最大值
                deq.pop_front();
                deq.push_back(nums[i + k]);
                maxnum = nums[i + k];
                result.push_back(maxnum);
                continue;
            }
            if(deq.front() != maxnum && nums[i + k] <= maxnum){//如果最大值未出队，且新加入的数小于当前最大值，那最大值一定在deque中
                deq.pop_front();
                deq.push_back(nums[i + k]);
                result.push_back(maxnum);
                continue;
            }
            if(deq.front() == maxnum){//如果最大值出队了，那需要重新遍历deque找到最大值
                deq.pop_front();
                deq.push_back(nums[i + k]);
                cur = nums[i + 1];//i+1才是这个双端序列的开头
                for(int x : deq){
                    cur = max(cur, x);
                }
                maxnum = cur;
                result.push_back(maxnum);
                continue;
            }
        }
        return result;
    }
};