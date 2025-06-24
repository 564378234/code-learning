#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(tokens[i] == "+")st.push(a + b);
                if(tokens[i] == "-")st.push(a - b);
                if(tokens[i] == "*")st.push(a * b);
                if(tokens[i] == "/")st.push(a / b);
            }else {
                st.push(stoi(tokens[i]));//字符串转int
            }
        }
        return st.top();
    }
};