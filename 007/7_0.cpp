#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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