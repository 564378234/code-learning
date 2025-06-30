#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int length, high1, S;
        int result = 0;
        int n = height.size();
        int left = 0, right = n - 1;
        while(left < right){
            length = right - left;
            high1 = min(height[left], height[right]);
            S = length * high1;
            result = max(result, S);
            if(height[left] <= height[right]){
                left++;
            }else{
                right--;
            }
        }
        return result;
    }
};