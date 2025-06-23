# include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        int n = s.size();
        for(int i = 0; i < n; i++){
            switch(s[i]){
                case '(':
                s1.push(1);
                break;
                case '[':
                s1.push(2);
                break;
                case '{':
                s1.push(3);
                break;
                case ')':
                if(s1.empty()){
                    return false;
                }
                if(s1.top() != 1){
                    return false;
                }
                s1.pop();
                break;
                case ']':
                if(s1.empty()){
                    return false;
                }
                if(s1.top() != 2){
                    return false;
                }
                s1.pop();
                break;
                case '}':
                if(s1.empty()){
                    return false;
                }
                if(s1.top() != 3){
                    return false;
                }
                s1.pop();
                break;
            }
        }
        if(s1.empty()){
            return true;
        }else {
            return false;
        }
    }
};

//另一种方法
class Solution02 {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        for (char c : s) {
            if (pairs.count(c)) {  // 如果是右括号
                if (st.empty() || st.top() != pairs[c]) return false;
                st.pop();// 把匹配的出栈
            } else {  // 左括号直接入栈
                st.push(c);
            }
        }
        return st.empty();
    }
};