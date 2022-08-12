#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // if(left == nullptr) return right;
        // if(right == nullptr) return left;
        // return root;
        return !left ? right : !right ? left : root;
    }
    void inorderTraversal(TreeNode *p1){
        if(p1){
            inorderTraversal(p1->left);
            cout<<p1->val<<" ";
            inorderTraversal(p1->right);
        }
    }
};
int main(){
    TreeNode *p1 = new TreeNode(6);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(8);
    TreeNode *p4 = new TreeNode(0);
    TreeNode *p5 = new TreeNode(4);
    TreeNode *p6 = new TreeNode(7);
    TreeNode *p7 = new TreeNode(9);
    TreeNode *p8 = new TreeNode(3);
    TreeNode *p9 = new TreeNode(5);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    p5->left = p8;
    p5->right = p9;

    Solution s;
    // s.inorderTraversal(p1);
    TreeNode *res = s.lowestCommonAncestor(p1, p2, p3);
    cout<<res->val<<" ";
    return 0;
}