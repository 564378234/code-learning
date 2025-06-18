#include <unordered_set>
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    //创建一个哈希表
    unordered_map<char, char> pairs = {
        //键是x，值是fx
        //输入x，返回fx
        //访问方式：pairs['x']
        //pairs.count('x')返回1,说明含有名为'x'的键
        {'x', 'fx'},
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
}