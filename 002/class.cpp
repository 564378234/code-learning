#include <iostream>
using namespace std;

// 定义链表结构体
struct ListNode{
    int val;//数据值，这俩是成员变量
    ListNode* next;//指向下一个的指针，这俩是成员变量
    ListNode() : val(0), next(nullptr){}//{}代表构造函数的函数体，空为不进行任何额外操作
    ListNode(int x) : val(x), next(nullptr){}//构造函数，接受一个参数x ，：之后代表初始化列表，在对象创建时直接初始化成员变量
    //默认的单参数构造函数可以隐式转换ListNode a = 12; 相当于 ListNode a = ListNode(12);
    ListNode(int x, ListNode* next01) : val(x), next(next01){}
};


int main() {
    // （1）这里直接初始化对象
    ListNode a = 12; //相当于 ListNode a = ListNode(12);
    //这里的链表只有一个元素，值为12，next为nullptr
    // 打印验证
    cout << a.val << endl; // 12，使用 “ . ” 访问成员变量

    // （2）扩充下一个元素为20
    a.next = new ListNode(20);//new分配内存，返回指针？
    //这里a是对象（ListNode 类型）a.val可以，a->val不行
    //a.next是指针（ListNode* 类型），a.next->val可以，a.next.val不行
    // 打印验证
    cout << a.val << " -> " << a.next->val << endl; // 12->20

    // （3）扩充下一个元素为30
    a.next->next = new ListNode(30);
    // 打印验证
    cout << a.val << " -> " << a.next->val << " -> " << a.next->next->val << endl; // 12->20->30

    // （4）释放内存
    delete a.next->next;
    delete a.next;

    //另一种方式初始化一个链表的第一个元素
    ListNode* b = new ListNode(12);
    cout << b->val << endl; // 12
    b->next = new ListNode(20);
    cout << b->val << " -> " << b->next->val << endl; // 12->20
    //这里删除了两个节点，上一个保留了a
    delete b->next;
    delete b;

    //创建一个空链表，没有值只有一个指向nullptr的指针
    ListNode* list = nullptr;

    return 0;
}