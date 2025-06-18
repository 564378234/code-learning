#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode* next):val(x),next(next){}
};

// 打印链表函数
void printList(ListNode* head){
    ListNode* cur = head;
    while(cur != nullptr){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

// 创建链表函数
ListNode* createList(int arr[],int n){
    if(n == 0)return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for(int i = 1;i < n;i++){
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

// 释放链表内存函数
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

class Solution {
    public:
        ListNode* reverse(ListNode* head){
            // 一个空链表，无节点，只有一个指针指向nullptr
            ListNode* list = nullptr;
            ListNode* p = head;
            while(p != nullptr){
                ListNode* tmp = p;
                p = p->next;
                tmp->next = list;
                list = tmp;
            }
            return list;
        }
};

int main() {
    Solution solution;
    
    // 测试用例1: 普通链表
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* list1 = createList(arr1, sizeof(arr1)/sizeof(arr1[0]));
    cout << "原始链表1: ";
    printList(list1);
    
    ListNode* reversed1 = solution.reverse(list1);
    cout << "反转后链表1: ";
    printList(reversed1);
    deleteList(reversed1);
    
    // 测试用例2: 空链表
    ListNode* list2 = nullptr;
    cout << "\n原始链表2: ";
    printList(list2);
    
    ListNode* reversed2 = solution.reverse(list2);
    cout << "反转后链表2: ";
    printList(reversed2);
    deleteList(reversed2);
    
    // 测试用例3: 单节点链表
    int arr3[] = {1};
    ListNode* list3 = createList(arr3, sizeof(arr3)/sizeof(arr3[0]));
    cout << "\n原始链表3: ";
    printList(list3);
    
    ListNode* reversed3 = solution.reverse(list3);
    cout << "反转后链表3: ";
    printList(reversed3);
    deleteList(reversed3);
    
    // 测试用例4: 两节点链表
    int arr4[] = {1, 2};
    ListNode* list4 = createList(arr4, sizeof(arr4)/sizeof(arr4[0]));
    cout << "\n原始链表4: ";
    printList(list4);
    
    ListNode* reversed4 = solution.reverse(list4);
    cout << "反转后链表4: ";
    printList(reversed4);
    deleteList(reversed4);
    
    return 0;
}