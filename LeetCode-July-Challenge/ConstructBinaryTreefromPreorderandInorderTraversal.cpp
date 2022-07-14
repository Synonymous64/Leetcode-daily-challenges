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
    int preIdx = 0;
    TreeNode *build(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start > end) return NULL;
        TreeNode *root = new TreeNode(preorder[preIdx]);
        preIdx++; int inIdx = 0;
        for(int i = start; i <= end; ++i){
            if(root->val == inorder[i]){
                inIdx = i;
                break;
            }
        }
        root->left = build(preorder, inorder, start, inIdx - 1);
        root->right = build(preorder, inorder, inIdx + 1, end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
    void inorder(TreeNode *root){
        if(root){
            inorder(root->left);
            cout<<root->val<<" ";
            inorder(root->right);
        }
    }
};
int main(){
    vector<int> preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);
    s.inorder(root);
    return 0;
}