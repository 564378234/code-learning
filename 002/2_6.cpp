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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* head00 = new ListNode(0, head);
        ListNode* cur = head00;
        ListNode* fastcur = head00;
        while(cur->next != nullptr){
            if(n > 0){
                fastcur = fastcur->next;
                n--;
                continue;
            }
            cur = cur->next;
            fastcur = fastcur->next;
        }
        //删除节点，释放内存
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        //保存结果，释放内存
        ListNode* result = head00->next;
        delete head00;
        return result;
    }
};