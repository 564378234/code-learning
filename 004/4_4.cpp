#include <iostream>
#include <string>
using namespace std;

// class Solution {
// public:
//     //如果修改完return s；会导致空间复杂度为o(n)，直接修改原字符串可以降为o(1)
//     void reverse(string &s, int start, int end){
//         while(start < end){
//             swap(s[start], s[end]);
//             start++;
//             end--;
//         }
//     }
//     string reverseWords(string s) {
//         int n = s.size();
//         int fast = 0, slow = 0;
//         if(n == 0)return s;
//         while(s[fast] == ' ' && fast < n)fast++;
//         for(; fast < n; fast++){
//             if(s[fast] != ' '){
//                 s[slow] = s[fast];
//                 slow++;
//             }else if(fast < n - 1 && s[fast] == ' ' && s[fast + 1] != ' '){
//                 s[slow] = s[fast];
//                 slow++;
//             }
//         }//空格去重完成，修改s的空间为slow的大小
//         s.resize(slow);//方法直接调用不用返回
//         reverse(s, 0, slow - 1);
//         int start = 0, end = 0;
//         for(int i = 0; i < slow; i++){
//             if(s[i] == ' '){
//                 end = i - 1;
//                 reverse(s, start, end);
//                 start = i + 1;
//             }
//             if(i == slow - 1){
//                 reverse(s, start, slow - 1);
//             }
//         }
//         return s;
//     }
// };

class Solution1 {
public:
    string reverseWords(string s) {
        string result;
        int n = s.size();
        int left = n - 1, right = n - 1;
        while(left >= 0){
            while(left >= 0 && s[left] == ' ')left--;
            if(left < 0)break;
            if(s[left] != ' '){
                right = left;//单词的起始位置
                while(left >= 0 && s[left] != ' ')left--;
                result += s.substr(left + 1, right - left);//此时left指向单词前面那个空格,substr(start, end)返回从start到end的子串
                result += ' ';
            }
        }
        if(!result.empty())result.pop_back();//如果是非空，就执行，pop_back()删除最后一个字符
        return result;
    }
};

int main() {
    Solution1 sol;
    
    // 测试用例
    string test1 = "the sky is blue";
    string test2 = "  hello world  ";
    string test3 = "a good   example";
    string test4 = "  Bob    Loves  Alice   ";
    string test5 = "Alice";
    string test6 = "";
    string test7 = "   ";
    
    // 测试并输出结果
    cout << "Test 1: \"" << test1 << "\" -> \"" << sol.reverseWords(test1) << "\"" << endl;
    cout << "Test 2: \"" << test2 << "\" -> \"" << sol.reverseWords(test2) << "\"" << endl;
    cout << "Test 3: \"" << test3 << "\" -> \"" << sol.reverseWords(test3) << "\"" << endl;
    cout << "Test 4: \"" << test4 << "\" -> \"" << sol.reverseWords(test4) << "\"" << endl;
    cout << "Test 5: \"" << test5 << "\" -> \"" << sol.reverseWords(test5) << "\"" << endl;
    cout << "Test 6: \"" << test6 << "\" -> \"" << sol.reverseWords(test6) << "\"" << endl;
    cout << "Test 7: \"" << test7 << "\" -> \"" << sol.reverseWords(test7) << "\"" << endl;
    
    return 0;
}