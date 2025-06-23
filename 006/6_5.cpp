#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st, tmp;
        string result;
        for(char x : s){//先用栈存储
            if(st.empty()){
                st.push(x);
            }else if(st.top() != x){
                st.push(x);
            }else {
                st.pop();
            }
        }
        while(!st.empty()){//将栈中的元素倒序输出
            tmp.push(st.top());
            st.pop();
        }
        while(!tmp.empty()){//填充结果字符串
            result += tmp.top();
            tmp.pop();
        }
        return result;
    }
};

class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for(char x : s){//直接操作字符串
            if(result.empty() || x != result.back()){
                result += x;
            }else if(x == result.back()){
                result.pop_back();
            }
        }
        return result;
    }
};