#include <iostream>
#include <string>
#include <algorithm>//包含reverse函数
using namespace std;

// int main(){
//     //将最后的x字符移到最前面，使用了新空间
//     int x;
//     string s;
//     cin >> x;
//     cin >> s;
//     int n = s.size();
//     string result;
//     int left = n - 1, right = n - 1;
//     while(left >= 0 && x > 0){
//         x--;
//         left--;
//     }
//     result += s.substr(left + 1, right - left);
//     result += s.substr(0, left + 1);
//     cout << result << endl;
// }

//另一种方法，直接在原字符串上操作

#include <iostream>
#include <string>
using namespace std;

void r(string &s, int start, int end){
    while(start < end){
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

int main(){
    int x;
    string s;
    cin >> x;
    cin >> s;
    int n = s.size();
    // r(s, 0, n - 1);
    // r(s, 0, x - 1);
    // r(s, x, n - 1);
    //直接使用库函数reverse
    reverse(s.begin(), s.end());//交换的字符范围是[0, n - 1]，也就是[s.begin(), s.end())，s.begin()表示字符串的第一个字符，s.end()表示字符串的最后一个字符的下一个位置
    reverse(s.begin(), s.begin() + x);//s.begin() + x指向的是第x+1个字符，即s[x]，但是交换是左闭右开
    reverse(s.begin() + x, s.end());
    cout << s << endl;
}