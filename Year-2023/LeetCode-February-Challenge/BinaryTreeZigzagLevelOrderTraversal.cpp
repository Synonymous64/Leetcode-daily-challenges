#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    vector<vector<int>> res;
    void levelorder(TreeNode *root){
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
            if(res.size() % 2 != 0) reverse(temp.begin(), temp.end());
            res.push_back(temp);
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        levelorder(root);
        return res;
    }
};
