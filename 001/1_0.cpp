#include <iostream>
#include <array> //这个是固定大小的内存数组，是栈
#include <vector> //这个是动态大小的内存数组，是堆，可以扩容
using namespace std;

int main(){
    //创建一个固定大小的数组（不能动态调整）,不用array和vector，直接用int[]也是可以的
    int arr01[5] = {1, 2, 3, 4, 5};
    cout << "arr01[0] = " << arr01[0] << endl;

    //补充，字符串可以通过s.resize(5 + s.size())来扩容
    string s = "hello";
    
    //使用array创建一个固定大小的数组
    array<int, 5> arr2 = {1, 2, 3, 4, 5};
    cout << "arr2[2]=" << arr2[2] << endl;
    cout << "arr2.at(3)=" << arr2[3] << endl;// at函数可以防止越界
    cout << "arr2.size()=" << arr2.size() << endl;//返回数组的大小
    cout << "arr2.front()=" << arr2.front() << endl;//返回第一个元素
    cout << "arr2.back()=" << arr2.back() << endl;//返回最后一个元素
    //修改元素就是直接修改
    arr2[1] = 10;
    cout << "arr2[1]=" << arr2[1] << endl;

    //使用vector创建一个动态大小的数组
    vector<int> arr3 = {1, 2, 3, 4, 5};
    arr3.push_back(6);//在数组末尾添加一个元素
    cout << "arr3.size()=" << arr3.size() << endl;
    cout << "arr3[5]=" << arr3[5] << endl;
    cout << "arr3[3]=" << arr3.at(3) <<endl;// at函数可以防止越界
    cout << "arr3.front()=" << arr3.front() << endl;//返回第一个元素
    cout << "arr3.back()=" << arr3.back() << endl;//返回最后一个元素
    arr3.pop_back();//删除数组末尾的元素
    cout << "arr3.pop_bake()删除了最后一个元素,arr3.size()=" << arr3.size() << endl;

    return 0;
}