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

class Solution{
    public:
    ListNode* removeElements(ListNode* head,int val){
        ListNode* head00 = new ListNode(0, head);
        ListNode* cur = head00;
        while(cur->next != nullptr){
            if(cur->next->val == val){
                //设置一个变量用来删除下一个节点
                ListNode* tmp = cur->next;
                //跳过目标值的节点
                cur->next = cur->next->next;
                //删除节点
                delete tmp;
            } else if(cur->next->val != val){
                cur = cur->next;
            }
        }
        ListNode* result = head00->next;
        delete head00;
        return result;
    }
};

int main() {
    Solution solution;
    
    // 测试用例1: 普通情况
    int arr1[] = {1, 2, 6, 3, 4, 5, 6};
    ListNode* list1 = createList(arr1, sizeof(arr1)/sizeof(arr1[0]));
    cout << "原始链表1: ";
    printList(list1);
    
    ListNode* result1 = solution.removeElements(list1, 6);
    cout << "删除6后的链表1: ";
    printList(result1);
    deleteList(result1);
    
    // 测试用例2: 删除头节点
    int arr2[] = {6, 6, 1, 2, 3};
    ListNode* list2 = createList(arr2, sizeof(arr2)/sizeof(arr2[0]));
    cout << "\n原始链表2: ";
    printList(list2);
    
    ListNode* result2 = solution.removeElements(list2, 6);
    cout << "删除6后的链表2: ";
    printList(result2);
    deleteList(result2);
    
    // 测试用例3: 空链表
    ListNode* list3 = nullptr;
    cout << "\n原始链表3: ";
    printList(list3);
    
    ListNode* result3 = solution.removeElements(list3, 1);
    cout << "删除1后的链表3: ";
    printList(result3);
    deleteList(result3);
    
    // 测试用例4: 所有节点都需要删除
    int arr4[] = {7, 7, 7, 7};
    ListNode* list4 = createList(arr4, sizeof(arr4)/sizeof(arr4[0]));
    cout << "\n原始链表4: ";
    printList(list4);
    
    ListNode* result4 = solution.removeElements(list4, 7);
    cout << "删除7后的链表4: ";
    printList(result4);
    deleteList(result4);
    
    // 测试用例5: 没有需要删除的节点
    int arr5[] = {1, 2, 3, 4};
    ListNode* list5 = createList(arr5, sizeof(arr5)/sizeof(arr5[0]));
    cout << "\n原始链表5: ";
    printList(list5);
    
    ListNode* result5 = solution.removeElements(list5, 5);
    cout << "删除5后的链表5: ";
    printList(result5);
    deleteList(result5);
    
    return 0;
}