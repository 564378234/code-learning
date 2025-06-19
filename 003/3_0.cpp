#include <unordered_set> //unordered_set是哈希表实现的
#include <iostream>
#include <unordered_map>
#include <set> //set是红黑树??????实现的
#include <vector>
using namespace std;

int main(){
    //数组也算一个哈希表看1_0.cpp

    //集合(有三个)
    //有序集合(set)
    set<int> set1 = {1, 2, 3, 4, 5}; //自动去重
    set1.insert(7); //插入元素
    set1.insert(5); //插入元素,重复元素无效
    set1.erase(2); //删除元素
    cout << "集合中的元素,会自动排序:";
    for(auto x : set1){
        cout << x << " ";//输出:1 3 4 5 7
    }
    cout << "\n集合大小:" << set1.size() << endl; //输出:5
    cout << "\nset1.count(3)集合是否包含元素3(实际上是计数):" << set1.count(3) << endl; //输出:1,实际上是计数，因为去重所以只能是1或0
    auto it = set1.find(5);//返回的是迭代器（iterator）？类型，是std::set<T>::iterator，用auto表达比较方便，不能用int
    cout << "\nset1.find(5)返回的迭代器指向的元素:" << *it << endl; //输出:5
    if(it != set1.end()){
        cout << "\n查找集合中包含元素5" << endl;
        set1.erase(it);//剩余元素:1 3 4 7
    }
    set1.erase(set1.begin(), next(set1.begin(), 2));//set1.begin(), next(set1.begin(), 2)是两个迭代器的方法，删除前两个元素，剩余元素:4 7
    set1.clear(); //清空集合，set1.size() == 0

    //无序集合(unordered_set),数字，字符，字符串等都可以
    unordered_set<char> set2 = {'a', 'b', 'c', 'd', 'e', 'a'};//自动去重
    set2.insert('f');
    set2.insert('a');//插入元素,重复元素无效
    for(auto x : set2){
        cout << x << " ";//输出全部元素，无序每次都不一样吗？？？？？
    }
    auto it2 = set2.find('b');//迭代器查找元素，然后删除
    if(it2 != set2.end()){
        set2.erase(it2);//
    }
    //多重有序集合(multiset)
    //将其他容器中的元素去重
    vector<int> vector1 = {1, 2, 3, 4, 5, 5, 5, 5};
    
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