#include <vector>
#include <deque>
using namespace std;

class Solution {//超时
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        int maxnum = nums[0], n = nums.size(), cur;
        vector<int> result;
        if(n == 1)return vector<int>{maxnum};//vector<int>{maxnum}，创建并添加一个maxnum元素，和vector<int>(maxnum)，创建maxnum个0元素，有什么区别
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

class Solution {//自己新建一个单调队列类
private://私有成员变量
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    class mydeque{
        public:
            deque<int> deq;//底层是deque
            void pop(int value){//这里处理要被移出队列的元素，如果deque的队首元素等于value，则删除
                if(!deq.empty() && value == deq.front()){
                    deq.pop_front();
                }
            }
            void push(int value){//处理进入队列的元素，从尾端元素开始比较，如果队尾元素小于value，无论如何他都不可能是该队列的最大值，删除
                while(!deq.empty() && deq.back() < value){
                    deq.pop_back();
                }
                deq.push_back(value);
            }
            int front(){//获取最大值
                return deq.front();
            }
    };
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        mydeque deq;
        vector<int> result;
        for(int i = 0; i < k; i++){
            deq.push(nums[i]);
        }
        result.push_back(deq.front());
        for(int i = k; i < nums.size(); i++){
            deq.pop(nums[i - k]);
            deq.push(nums[i]);
            result.push_back(deq.front());
        }
        return result;
    }
};