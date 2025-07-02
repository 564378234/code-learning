#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count[128] = {0};//ascii编码有128个，因为数量相应，所以直接count['A']++;就可以直接计数char
        int n = s.size();
        int left = 0, right = 0, num = 0;
        while(right < n){
            while(right < n && count[s[right]] == 0){//为什么加上right<n就可以让输入一个空格从输出2（错误）变成输出1（正确）
                count[s[right]]++;
                right++;
            }
            num = max(num, right - left);
            while(s[left] != s[right]){//这里不加right<n就可以成立
                count[s[left]]--;
                left++;
            }
            left++;
            right++;
        }
        return max(num, right - left);
    }
};