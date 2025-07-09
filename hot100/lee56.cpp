#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        if(n == 1)return res = intervals;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
        res.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            vector<int>& last = res.back();//使用&所以改变last[1]会直接改变res里的结果
            if(last[1] >= intervals[i][0]){
                last[1] = max(last[1], intervals[i][1]);//使用&所以可以直接改结果
            }else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};