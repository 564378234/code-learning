#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map12;
        int count = 0;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                int sum12 = nums1[i] + nums2[j];//因为只需要次数，所以sum12对应的值只需要是次数就好，不用记录编号
                map12[sum12] += 1;
                sum12 = 0;
            }
        }
        for(int i = 0; i < nums3.size(); i++){
            for(int j = 0; j < nums4.size(); j++){
                int sum34 = nums3[i] + nums4[j];
                if(map12.find(-sum34) != map12.end()){
                    count += map12[-sum34];
                }
                sum34 = 0;
            }
        }
        return count;
    }
};