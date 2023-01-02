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
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        while(curr){
            if(curr->left){
                TreeNode *pred = curr->left;
                while(pred->right) pred = pred->right;
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
int main(){
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(5);
    TreeNode *p4 = new TreeNode(3);
    TreeNode *p5 = new TreeNode(4);
    TreeNode *p6 = new TreeNode(6);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->right = p6;

    Solution s;
    s.flatten(p1);
    while(p1->right){
        cout<<p1->val<<" ";
        p1 = p1->right;
    } cout<<endl;
    return 0;
}