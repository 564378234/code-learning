using namespace std;
#include <iostream>

// 定义链表结构体
struct ListNode{
    int val;//数据值
    ListNode* next;//指向下一个的指针
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}//构造函数，接受一个参数x ，：之后代表初始化列表，在对象创建时直接初始化成员变量
    ListNode(int x, ListNode* next01) : val(x), next(next01){}
};

