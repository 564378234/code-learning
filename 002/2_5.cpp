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
    ListNode* swapPairs(ListNode* head){
        ListNode* head00 = new ListNode(0, head);
        ListNode* cur = head00;
        if(head == nullptr || head->next == nullptr){
            delete head00;
            return head;
        }
        while(cur->next != nullptr && cur->next->next != nullptr){
            // 这样不是拷贝出一个新的链表，而是新建了一个指针，对tmp->next修改也会修改原链表
            ListNode* tmp = cur->next;
            ListNode* tmp1 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp1;
            cur = cur->next->next;
        }
    }
};