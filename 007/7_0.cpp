#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>//包含reverse函数
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//栈的操作方法一般是push(), pop(), top(), empty()
//push_back()是序列容器的，如vector, deque, list, string, array

class Solution1 {//前序排列的递归方法
    public:
        void traversal(TreeNode* trnode, vector<int>& res){//res应该使用引用传递(带&),不带&是值传递无法改变外部的result
            if(trnode == nullptr)return;//应该比较trnode == NULL，NULL是空指针常量，trnode->val是int，trnode是指针
            res.push_back(trnode->val);
            traversal(trnode->left, res);
            traversal(trnode->right, res);
        }
        vector<int> preorderTraversal(TreeNode* root){
            vector<int> result;
            traversal(root, result);
            return result;
        }
};

class Solution2 {//中序排列的递归方法
    public:
        void travesal(TreeNode* trnode, vector<int>& res){
            if(trnode == nullptr)return;
            travesal(trnode->left, res);
            res.push_back(trnode->val);
            travesal(trnode->right, res);
        }
        vector<int> inorderTraversal(TreeNode* root){
            vector<int> result;
            travesal(root, result);
            return result;
        }
};

class Solution3 {//后序排列的递归方法
    public:
        void travesal(TreeNode* trnode, vector<int>& res){
            if(trnode == nullptr)return;
            travesal(trnode->left, res);
            travesal(trnode->right, res);
            res.push_back(trnode->val);
        }
        vector<int> postorderTraversal(TreeNode* root){
            vector<int> result;
            travesal(root, result);
            return result;
        }
};

class Solution4 {//前序排列的迭代方法
    public:
        vector<int> preorderTraversal(TreeNode* root){
            stack<TreeNode*> st;
            vector<int> result;
            if(root == nullptr)return result;//空的直接返回
            st.push(root);//将第一个节点入栈
            while(!st.empty()){
                TreeNode* node = st.top();//用一个TreeNode*类型的指针保存栈顶元素，这个是要处理的元素，同时也是先访问的节点，所以方便处理
                st.pop();
                result.push_back(node->val);
                if(node->right)st.push(node->right);//右节点先入栈，如果是空的就会跳过
                if(node->left)st.push(node->left);//左节点后入栈
            }//所有的右节点先入栈，如果有左节点，左节点会先出栈，同样的先入栈的右节点在树的更顶层，所以会后出栈
            return result;
        }
};

class Solution5 {//中序排列的迭代方法
    public:
        vector<int> inorderTraversal(TreeNode* root){
            vector<int> result;
            stack<TreeNode*> st;
            TreeNode* cur = root;//如果本节点没有左侧的子节点，那么处理当前节点while()，再将当前节点移到本节点的右侧子节点，按同样的逻辑继续处理
            while(cur != nullptr || !st.empty()){//如果当前节点不为空或者栈不为空，那么就继续循环
                if(cur != nullptr){//一直访问到最底层
                    st.push(cur);
                    cur = cur->left;
                }else {//如果当前节点为空，那么就将栈顶元素出栈，并将当前节点移到右侧子节点
                    cur = st.top();//当前为nullptr了，将cur移动到栈顶元素，也就是最底层的左侧子节点
                    st.pop();
                    result.push_back(cur->val);
                    cur = cur->right;//处理完移动到右侧节点，循环
                }
            }
            return result;
        }
};

class Solution6 {//后序排列的迭代方法
    public:
        vector<int> postorderTraversal(TreeNode* root){
            stack<TreeNode*> st;
            vector<int> result;
            if(root == nullptr)return result;
            st.push(root);
            while(st.empty()){
                TreeNode* node = st.top();
                st.pop();
                result.push_back(node->val);
                if(node->left != nullptr)st.push(node->left);
                if(node->right != nullptr)st.push(node->right);
            }
            reverse(result.begin(), result.end());
            return result;
        }
};

class Solution7 {//层序遍历
    public:
        vector<vector<int>> levelOrder(TreeNode* root){
            queue<TreeNode*> que;
            if(root != nullptr)que.push(root);
            vector<vector<int>> result;
            while(!que.empty()){
                int size = que.size();//存入一层节点，保存且出队的同时将下一层节点存入
                vector<int> partofresult;
                for(int i = 0; i < size; i++){
                    TreeNode* node = que.front();
                    que.pop();//队列的pop()是将头元素出队
                    partofresult.push_back(node->val);
                    if(node->left != nullptr)que.push(node->left);
                    if(node->right != nullptr)que.push(node->right);
                }
                result.push_back(partofresult);
            }
            return result;
        }
};

class Solution8 {//层序遍历的递归方法
    public:
        void order(TreeNode* cur, vector<vector<int>>& result, int level){//如果order的名字跟变量相同，在函数内部调用时会报错
            if(cur == nullptr)return;//退出条件，遇到空指针就直接返回
            if(result.size() == level)result.push_back(vector<int>{});//result.size() == level结果容器的大小（从1开始）等于层数（从0开始），说明需要新建一层容器
            result[level].push_back(cur->val);//将当前节点值存入对应层容器
            order(cur->left, result, level + 1);//递归遍历左子树
            order(cur->right, result, level + 1);//递归遍历右子树
        }
        vector<vector<int>> levelOrder(TreeNode* root){
            vector<vector<int>> result;
            int level = 0;
            order(root, result, level);
            return result;
        }
};