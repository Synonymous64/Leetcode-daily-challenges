#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value) {
        left = nullptr;
        right = nullptr;
    }
};
class Solution {
private : 
    vector<vector<int>> res;
    void levelorderTraversal(TreeNode *root){
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                TreeNode *curr = q.front();
                temp.push_back(curr->val);
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            res.push_back(temp);
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return res;
        levelorderTraversal(root);
        return res;
    }
    void printCode(){
        for(int i = 0; i < res.size(); ++i){
            for(int j = 0; j < res[i].size(); ++j){
                cout<<res[i][j]<<" ";
            }
        }
    }
};
int main(){
    TreeNode *p1 = new TreeNode(3);
    TreeNode *p2 = new TreeNode(9);
    TreeNode *p3 = new TreeNode(20);
    TreeNode *p4 = new TreeNode(15);
    TreeNode *p5 = new TreeNode(7);

    p1->left = p2;
    p1->right = p3;
    p3->left = p4;
    p3->right = p5;

    Solution s;
    s.levelOrder(p1);
    s.printCode();
    return 0;
}