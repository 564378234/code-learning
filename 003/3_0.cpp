#include <unordered_set> //unordered_set是哈希表实现的
#include <iostream>
#include <unordered_map>
#include <set> //set是红黑树??????实现的,这里面还有一个multiset,可以重复
#include <vector>
#include <map> //map红黑树实现
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
    //迭代器也有一种遍历方法，就是用解引用运算符*，例如for (auto it = ms.begin(); it != ms.end(); ++it)然后cout << *it << endl;
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
    cout << "\n输出全部元素:" << endl;
    for(auto x : set2){
        cout << x << " ";//输出全部元素，无序每次都不一样吗？？？？？
    }
    cout << "\n迭代器查找然后删除'b':" << endl;
    auto it2 = set2.find('b');//迭代器查找元素，然后删除
    if(it2 != set2.end()){
        set2.erase(it2);//剩余元素:a c d e f
    }
    set2.clear();//清空集合

    //多重有序集合(multiset)(允许重复)
    multiset<int> set3 = {1, 2, 3, 3, 4, 5, 5};//char类型是按ascii码排序的，string类型是按字典序排序的
    set3.insert(3);//插入元素，重复元素有效
    set3.erase(5);//删除值为5的元素，剩余元素:1 2 3 3 3 4
    cout << "\n输出全部元素:" << endl;
    for(auto x : set3){
        cout << x << " ";
    }
    cout << "\n迭代器查找然后删除'3',迭代器只删除一个重复的元素:" << endl;
    auto it3 = set3.find(3);//迭代器查找元素，然后删除
    if(it3 != set3.end()){
        set3.erase(it3);//使用迭代器只删除一个元素，剩余元素:1 2 3 3 4
    }
    set3.erase(set3.begin(), next(set3.begin(), 2)); // 删除前两个元素，剩余元素:3 3 4
    set3.erase(set3.begin(), set3.end());//清空集合
    set3.clear();//清空集合

    ////////////////////////////////////////////////////////////////////////////
    //将其他容器中的元素去重，可以先转换成set(有序)，unordered_set(无序)然后再转换回来
    vector<int> vector1 = {1, 2, 3, 4, 5, 5, 5, 5};
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    vector<int> vector2 = {1, 2, 3, 4, 5, 5, 5, 5};
    set<int> newvector2;
    set<int> newvector1(vector1.begin(), vector1.end());//将vector1中的元素转换成set1，去重，有序
    unordered_set<int> newarr(begin(arr), end(arr));//将arr中的元素转换成set2，去重，无序
    //遍历的方式去重
    for(int x : vector2){
        newvector2.insert(x);//插入元素，重复元素无效,可以进行其他if操作
    }
    //转换回vector，然后再return unique_vec
    vector<int> unique_vec(newvector1.begin(), newvector1.end());
    //也可以不新命名，直接return vector<int>(newvector1.begin(), newvector1.end());
    ////////////////////////////////////////////////////////////////////////////
    
    //键值对(有三个)
    unordered_map<char, char> pairs00 = {
        //键是x，值是fx
        //输入x，返回fx
        //访问方式：pairs['x']
        //pairs.count('x')返回1,说明含有名为'x'的键
        {'x', 'fx'},//双引号代表字符串string，单引号里的多字符代表多字符字面量，类型是int，输入和输出都难以区分
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    //有序唯一键值对：map
    map<string, int> map1 = {
        {"xiao1", 25},//双引号代表字符串string，单引号变成了int类型
        {"xiao2", 30}
    };
    for(const auto& [key, val] : map1){//const用来防止修改键值对的元素，auto&中的&用来防止拷贝提高效率
        cout << key << " " << val << endl;//输出键值对
    }
    map1["xiao2"] = 26;//修改键值对
    map1["xiao3"] = 28;//添加键值对
    map1.insert({"xiao4", 35});//使用方法insert()添加，如果存在则失效
    map1.emplace("xiao5", 40);//方法emplace()
    cout << "使用extract()提取键值对，修改键或值" << endl;
    auto node1 = map1.extract("xiao1");//提取键值对（此时键值对已经被拿出容器了，修改后需要再次放回），返回一个node，可以插入到其他map中
    if(!node1.empty()){//也可以用empty()检查map1是否为空
        node1.key() = "xiao1_1";
        node1.mapped() = 25;//修改节点值的方法
        map1.insert(move(node1));//move()用来移动node，防止拷贝，将节点再次放回容器
    }
    cout << "使用erase()删除键值对" << endl;
    map1.erase("xiao4");//删除键值对
    // map1.erase(map1.begin(), next(map1.begin(), 2));//删除前两个键值对
    auto it4 = map1.find("xiao2");//find()查找键值对，返回一个迭代器
    if(it4 != map1.end()){//检查是否找到
        cout << it4->first << " " << it4->second << endl;//输出键值对
    }
    //无序唯一键值对：unordered_map
    //有序不唯一键值对：multimap

}