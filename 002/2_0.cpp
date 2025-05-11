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

//初始化节点
int main() {
    ListNode* secondPtr = new ListNode(13);
    ListNode* head = new ListNode(12, secondPtr);

    // 打印验证
    cout << head->val << " -> " << head->next->val << endl; // 输出：12.5 -> 13.5

    // 清理内存,必须
    delete head->next;
    delete head;
    return 0;
}

// class Solution{
//     public:
//     ListNode* removeElements(ListNode* head,int val){}
// };