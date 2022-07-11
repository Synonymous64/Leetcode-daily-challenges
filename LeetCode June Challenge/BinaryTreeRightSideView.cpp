#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value){
        left = nullptr;
        right = nullptr;
    } 
    TreeNode (int value, TreeNode *leftPtr) : val(value), left(leftPtr){
        right = nullptr;
    }
    TreeNode (int value, TreeNode *leftPtr, TreeNode *rightPrt) : val(value), left(leftPtr), right(rightPrt) {}
};
//! Iterative Approach
// class Solution {
// private:
//     vector<int> res;
//     void levelorderHelper(TreeNode *root){
//         if(!root) return;
//         queue<TreeNode *> q;
//         q.push(root);
//         while(!q.empty()){
//             int count = q.size();
//             while(count-- > 0){
//                 TreeNode *curr = q.front();
//                 q.pop();
//                 if(count == 0){
//                     res.push_back(curr->val);
//                 }
//                 if(curr->left) q.push(curr->left);
//                 if(curr->right) q.push(curr->right);
//             }
//         }
//     }
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         levelorderHelper(root);
//         return res;
//     }
//     void printCode(vector<int> &nums){
//         for(int i = 0; i < nums.size(); ++i){
//             cout<<nums[i]<<" ";
//         }
//     }
// };
// int main(){
//     TreeNode *p1 = new TreeNode(1);
//     TreeNode *p2 = new TreeNode(2);
//     TreeNode *p3 = new TreeNode(3);
//     TreeNode *p4 = new TreeNode(4);
//     TreeNode *p5 = new TreeNode(5);

//     p1->left = p2;
//     p1->right = p3;
//     p2->right = p5;
//     p3->right = p4;

//     Solution s;
//     vector<int> nums = s.rightSideView(p1);
//     s.printCode(nums);
    
//     return 0;  
// }
// ! Recursive Approach
class Solution {
private:
    vector<int> res;
    void helper(TreeNode *root, int level){
        if(!root) return;
        if(res.size() < level) res.push_back(root->val);
        helper(root->right, level + 1);
        helper(root->left, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        helper(root, 1);
        return res;
    }
    void printCode(vector<int> &nums){
        for(int i = 0; i < nums.size(); ++i){
            cout<<nums[i]<<" ";
        }
    }
};
int main(){
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    TreeNode *p5 = new TreeNode(5);

    p1->left = p2;
    p1->right = p3;
    p2->right = p5;
    p3->right = p4;

    Solution s;
    vector<int> nums = s.rightSideView(p1);
    s.printCode(nums);
    
    return 0;  
}