#include <iostream>
// #include <string>
using namespace std;

class Solution{
    public:
    string reverseStr(string s, int k){
        int left, right;
        int n = s.size();
        for(int i = 0; i < n; i += 2*k){
            left = i;
            right = min(i + k -1, n - 1);
            // 这样的条件不用计算需要调整的字符串的一半是多少
            while(left < right){
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};