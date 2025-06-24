#include <string>
#include <iostream>
using namespace std;

int main(){
    string s = "hello";
    s[0] = 'H';
    cout << s << endl;
    cout << "s.front()是访问字符串的首位" << s.front() << endl;
    cout << "s.back()是访问字符串的末位" << s.back() << endl;
    s.push_back('!');
    cout << "s.push_back()是在字符串末尾添加一个字符" << s << endl;
    s.pop_back();
    cout << "s.pop_back()是删除字符串末尾的字符" << s << endl;
    s.append(" world");
    cout << "s.append()是在字符串末尾添加一个字符串" << s << endl;
    s.insert(6, " my");
    cout << "s.insert()是在指定位置插入一个字符串" << s << endl;
    s.erase(6, 2);
    cout << "s.erase()是删除指定位置的字符串" << s << endl;
    s.replace(6, 2, " your");
    cout << "s.replace()是替换指定位置的字符串" << s << endl;
    // s.clear();//清空字符串

    //如果是一个字符串的容器vector<string>，可以使用stoll("string to long long" 的缩写)或stol或stoi将字符串转换为整数
    string s1 = "123";
    long long a = stoll(s1);
    //如果是一个字符串的容器vector<int>，可以使用to_string将整数转换为字符串
    int b = 123;
    string s2 = to_string(b);
    return 0;
}