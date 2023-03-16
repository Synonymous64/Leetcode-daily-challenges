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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(!inorder.size() || !postorder.size()) return 0;
        TreeNode *root = new TreeNode(postorder.back());
        if(postorder.size() == 1) return root;
        auto rootIdx = find(inorder.begin(), inorder.end(), postorder.back()) - inorder.begin();
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIdx);
        vector<int> rightInorder(inorder.begin() + rootIdx + 1, inorder.end());
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + rootIdx);
        vector<int> rightPostorder(postorder.begin() + rootIdx, postorder.end() - 1);
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);
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
    vector<int> inorder = {9,3,15,20,7}, postorder = {9,15,7,20,3};
    Solution *s = new Solution();
    TreeNode *newTree = s->buildTree(inorder, postorder);
    s->inorderTraversal(newTree);
    return 0;
}