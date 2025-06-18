#include <iostream>
// #include <string>
using namespace std;

class Solution{
    public:
    string reverseString(string s){
        for(int i = 0, j = s.size() - 1; i < j; i++, j--){
            swap(s[i], s[j]);
        }
        return s;
    }
};

int main() {
    Solution sol;
    
    // 测试用例1：普通字符串
    string s1 = "hello";
    cout << "Original: " << s1 << endl;
    cout << "Reversed: " << sol.reverseString(s1) << endl;
    cout << endl;

    // 测试用例2：空字符串
    string s2 = "";
    cout << "Original: " << s2 << endl;
    cout << "Reversed: " << sol.reverseString(s2) << endl;
    cout << endl;

    // 测试用例3：单个字符
    string s3 = "a";
    cout << "Original: " << s3 << endl;
    cout << "Reversed: " << sol.reverseString(s3) << endl;
    cout << endl;

    // 测试用例4：回文字符串
    string s4 = "madam";
    cout << "Original: " << s4 << endl;
    cout << "Reversed: " << sol.reverseString(s4) << endl;
    cout << endl;

    return 0;
}