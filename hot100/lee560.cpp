#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, result = 0;
        int n = nums.size();
        vector<int> sumvector = {};
        unordered_map<int, int> map = {//键是当前值-k（需要前缀和等于的值），值是出现次数
            {0, 1}
        };
        for(int x : nums){
            sum += x;
            sumvector.push_back(sum);
        }
        for(int i = 0; i < n; i++){
            if(map.find(sumvector[i] - k) != map.end()){//之前存储的键有目标值，result加上出现的次数
                result += map[sumvector[i] - k];
                if(map.find(sumvector[i]) != map.end()){//如果之前存在这个键，值加1，不存在就新建一个键
                    map[sumvector[i]]++;
                }else {
                    map[sumvector[i]] = 1;
                }
            }else {//在之前存储的键中没找到目标值
                if(map.find(sumvector[i]) != map.end()){//如果之前存在这个键，值加1，不存在就新建一个键
                    map[sumvector[i]]++;
                }else {
                    map[sumvector[i]] = 1;
                }
            }
        }
        return result;
    }
};

class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, result = 0;
        unordered_map<int, int> map = {//键是当前值-k（需要前缀和等于的值），值是出现次数
            {0, 1}
        };
        for(int x : nums){//一边计算前缀和一边判断
            sum += x;
            if(map.find(sum - k) != map.end()){//找到了目标值
                result += map[sum - k];
            }
            if(map.find(sum) != map.end()){//找到与否都要更新map，所以写在外面
                map[sum]++;
            }else{
                map[sum] = 1;
            }
        }
        return result;
    }
};