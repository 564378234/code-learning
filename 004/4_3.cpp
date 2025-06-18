#include <iostream>
using namespace std;

int main(){
    string s;
    int num = 0;
    int sumnum = 0;
    cin >> s;
    for(char x: s){
        //单引号才能代表char
        if(x >= '0' && x <= '9'){
            num++;
        }
        sumnum++;
    }
    //扩充字符串大小
    s.resize(s.size() + num * 5);
    int n = s.size() - 1;
    for(int i = sumnum - 1; i >= 0; i--){
        if(s[i] >= '0'&& s[i] <= '9'){
            s[n--] = 'r';
            s[n--] = 'e';
            s[n--] = 'b';
            s[n--] = 'm';
            s[n--] = 'u';
            s[n--] = 'n';
        }else{
            s[n--] = s[i];
        }
    }
    cout << s <<endl;
}