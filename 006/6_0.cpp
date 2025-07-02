#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(){
    //栈stack（先进后出）
    stack<int> st1;//底层容器为deque（默认），stack本身不存储数据，只是对deque进行封装，提供一些接口
    stack<int, vector<int>> st2;//底层容器为vector（也可以是list等），对内存有连续的要求才用
    
    //栈不能直接初始化时加入元素（他只是接口），只能通过push()加入元素
    st1.push(1);
    st1.push(2);
    st1.push(3);
    stack<int> st3(st1);//st3和st1元素相同，但是不是同一个栈
    stack<int> st4 = st1;//直接=也可以
    st1.size();//返回元素个数
    while(!st1.empty()){//empty()方法，如果是空的返回true，否则返回false
        cout << st1.top() << " ";//top()方法，返回栈顶元素
        st1.pop();//pop()方法，删除栈顶元素，什么都不返回
    }

    //队列queue（先进先出）
    queue<int> que1;//底层容器为deque，不能在初始化时加入元素
    que1.push(1);//队尾加入元素
    que1.push(2);
    que1.push(3);
    que1.size();//返回元素个数
    queue<int> que2(que1);
    while(!que1.empty()){
        cout << que1.front() << " ";//front()方法，返回队头元素
        que1.pop();//pop()方法，删除队头元素，什么都不返回
    }
    cout << que2.back() << " ";//back()方法，返回队尾元素

    //双端队列deque（两端都可以进出）
    deque<int> deq1 = {1,2,3,4,5};//初始化时加入元素
    deque<int> deq2(3, 100);//初始化时加入3个100
    vector<int> v1 = {10, 20, 30};
    deque<int> deq3(v1.begin(), v1.end());//初始化时加入v1的元素

    deq1.push_back(100);//队尾加入元素1, 2, 3, 4, 5, 100
    deq1.push_front(200);//队头加入元素200, 1, 2, 3, 4, 5, 100
    deq1.pop_back();//删除队尾元素200, 1 2, 3, 4, 5
    deq1.pop_front();//删除队头元素1, 2, 3, 4, 5
    cout << "front()可以访问头元素:" << deq1.front() << endl;//返回队头元素1
    cout << "back()可以访问尾元素:" << deq1.back() << endl;//返回队尾元素5
    deq1.insert(deq1.begin(), 300);//在队头插入元素300, 1, 2, 3, 4, 5，普通队列queue没有这个方法
    deq1[0] = 400;//可以直接访问和修改元素，0是队列的头元素300

    return 0;
}
