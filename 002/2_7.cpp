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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        int n;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA != nullptr){
            lenA++;
            curA = curA->next;
        }
        while(curB != nullptr){
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        n = lenA - lenB;
        if(n >= 0){
            // 加空指针检测
            while(n > 0 && curA != nullptr){
                curA = curA->next;
                n--;
            }
        }else if(n < 0){
            while(n < 0 && curB != nullptr){
                curB = curB->next;
                n++;
            }
        }
        while(curA != nullptr){
            // 用这个判断是否是同一个节点？
            if(curA == curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};