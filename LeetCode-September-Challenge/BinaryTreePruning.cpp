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
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root){
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
            if(root->val == 0 && !root->left && !root->right) return nullptr;
        }
        return root;
    }
    void inorderTraversal(TreeNode *root){
        if(root){
            inorderTraversal(root->left);
            cout<<root->val<<" ";
            inorderTraversal(root->right);
        }
    }
};
int main(){
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(0);
    TreeNode *p3 = new TreeNode(0);
    TreeNode *p4 = new TreeNode(1);

    p1->right = p2;
    p2->left = p3;
    p2->right = p4;
    Solution s;
    p1 = s.pruneTree(p1);
    s.inorderTraversal(p1);
    return 0;
}